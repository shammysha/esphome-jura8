#pragma once

#include "esphome.h"

#ifdef USE_SWITCH
#include "esphome/components/switch/switch.h"
#endif

#ifdef USE_BUTTON
#include "esphome/components/button/button.h"
#endif

#ifdef USE_TEXT_SENSOR
#include "esphome/components/text_sensor/text_sensor.h"
#endif

#include "esphome/components/uart/uart.h"
#include "esphome/core/helpers.h"

namespace esphome {
  namespace jura_coffee {

    class JuraCoffee : public PollingComponent, public uart::UARTDevice {
#ifdef USE_BUTTON
      SUB_BUTTON(left_top)
      SUB_BUTTON(left_middle)
      SUB_BUTTON(left_bottom)
      SUB_BUTTON(right_top)
      SUB_BUTTON(right_middle)
      SUB_BUTTON(right_bottom)
#endif

#ifdef USE_TEXT_SENSOR
      SUB_TEXT_SENSOR(tank)
      SUB_TEXT_SENSOR(tray)
#endif

#ifdef USE_SWITCH
      SUB_SWITCH(power)
#endif

      public:
        JuraCoffee();

        String cmd2jura(String outbytes);

        void setup() override;
        void update() override;
        void loop() override {}




      protected:
        std::string tray_status_;
        std::string tank_status_;
    };

  }
}
