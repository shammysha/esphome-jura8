#include "jura_coffee.h"
#include "esphome/core/log.h"

namespace esphome {
  namespace jura_coffee {

    JuraCoffee::JuraCoffee() {
    }

    void JuraCoffee::setup() {
      this->set_update_interval(10000); // 600000 = 10 minutes // Now 60 seconds
    }

    void JuraCoffee::update() {
      String result, hexString, substring;
      long bytes;
      int trayBit, tankBit;

      result = cmd2jura("IC:");
      ESP_LOGD("main", "Raw IC result: %s", result.c_str());
      hexString = result.substring(3, 8);
      ESP_LOGD("main", "hexString: %s", hexString.c_str());
      bytes = strtol(hexString.c_str(), NULL, 16);

      trayBit = (bytes & (1 << 12)) >> 12;
      tankBit = (bytes & (1 << 5)) >> 5;

      this->tray_status_ = (trayBit == 0 ? "Missing" : "Present");
      this->tank_status_ = (tankBit == 1 ? "Fill Tank" : "OK");

#ifdef USE_TEXT_SENSOR
      if (this->tray_text_sensor_ != nullptr) {
        this->tray_text_sensor_->publish_state(this->tray_status_);
      }
      if (this->tank_text_sensor_ != nullptr) {
        this->tank_text_sensor_->publish_state(this->tank_status_);
      }
#endif
    }

    std::string JuraCoffee::cmd2jura(std::string data) {
      while (this->available()) {
        this->read();
      }

      data += "\r\n";

      for (char c : data) {
        this->write_array(this->encode(static_cast<uint8_t>(c)));
        delay(8);
      }

      int s = 0;
      char inbyte;
      std::string inbytes;

      while (!inbytes.endsWith("\r\n")) {
        if (available()) {
          byte rawbyte = this->read();
          bitWrite(inbyte, s + 0, bitRead(rawbyte, 2));
          bitWrite(inbyte, s + 1, bitRead(rawbyte, 5));
          if ((s += 2) >= 8) {
            s = 0;
            inbytes += inbyte;
          }
        } else {
          delay(10);
        }
        if (w++ > 500) {
          return "";
        }
      }

      return inbytes.substring(0, inbytes.length() - 2);
    }

    std::array<uint8_t, 4> JuraCoffee::encode(const uint8_t &decData) {
      // 1111 0000 -> 0000 1111:
      uint8_t tmp = ((decData & 0xF0) >> 4) | ((decData & 0x0F) << 4);

      // 1100 1100 -> 0011 0011:
      tmp = ((tmp & 0xC0) >> 2) | ((tmp & 0x30) << 2) | ((tmp & 0x0C) >> 2) | ((tmp & 0x03) << 2);

      // The base bit layout for all send bytes:
      constexpr uint8_t BASE = 0b01011011;

      std::array < uint8_t, 4 > encData { };
      encData[0] = BASE | ((tmp & 0b10000000) >> 2);
      encData[0] |= ((tmp & 0b01000000) >> 4);

      encData[1] = BASE | (tmp & 0b00100000);
      encData[1] |= ((tmp & 0b00010000) >> 2);

      encData[2] = BASE | ((tmp & 0b00001000) << 2);
      encData[2] |= (tmp & 0b00000100);

      encData[3] = BASE | ((tmp & 0b00000010) << 4);
      encData[3] |= ((tmp & 0b00000001) << 2);

      return encData;
    }

    uint8_t JuraCoffee::decode(const std::array<uint8_t, 4> &encData) {
      // Bit mask for the 2. bit from the left:
      constexpr uint8_t B2_MASK = (0b10000000 >> 2);
      // Bit mask for the 5. bit from the left:
      constexpr uint8_t B5_MASK = (0b10000000 >> 5);

      uint8_t decData = 0;
      decData |= (encData[0] & B2_MASK) << 2;
      decData |= (encData[0] & B5_MASK) << 4;

      decData |= (encData[1] & B2_MASK);
      decData |= (encData[1] & B5_MASK) << 2;

      decData |= (encData[2] & B2_MASK) >> 2;
      decData |= (encData[2] & B5_MASK);

      decData |= (encData[3] & B2_MASK) >> 4;
      decData |= (encData[3] & B5_MASK) >> 2;

      // 1111 0000 -> 0000 1111:
      decData = ((decData & 0xF0) >> 4) | ((decData & 0x0F) << 4);

      // 1100 1100 -> 0011 0011:
      decData = ((decData & 0xC0) >> 2) | ((decData & 0x30) << 2) | ((decData & 0x0C) >> 2) | ((decData & 0x03) << 2);

      return decData;
    }

  }
}
