#include "jura_coffee.h"
#include "esphome/core/log.h"

namespace esphome {
namespace jura_coffee {

void JuraCoffee::setup() {
  this->set_update_interval(10000); // 600000 = 10 minutes // Now 60 seconds
}

String JuraCoffee::cmd2jura(String outbytes) {
  String inbytes;
  int w = 0;

  while (available()) {
    read();
  }

  outbytes += "\r\n";
  for (int i = 0; i < outbytes.length(); i++) {
    for (int s = 0; s < 8; s += 2) {
      char rawbyte = 255;
      bitWrite(rawbyte, 2, bitRead(outbytes.charAt(i), s + 0));
      bitWrite(rawbyte, 5, bitRead(outbytes.charAt(i), s + 1));
      write(rawbyte);
    }
    delay(8);
  }

  int s = 0;
  char inbyte;
  while (!inbytes.endsWith("\r\n")) {
    if (available()) {
      byte rawbyte = read();
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

void JuraCoffee::setup() override {
  this->set_update_interval(10000); // 600000 = 10 minutes // Now 60 seconds
}

void loop() override {}

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

  if (trayBit == 0) {
    tray_status = "Missing";
  } else {
    tray_status = "Present";
  }
  if (tankBit == 1) {
    tank_status = "Fill Tank";
  } else {
    tank_status = "OK";
  }

  if (xsensor6 != nullptr) xsensor6->publish_state(tray_status);
  if (xsensor7 != nullptr) xsensor7->publish_state(tank_status);
}

}}
