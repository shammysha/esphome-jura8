#include "esphome.h"
// #include <esphome/components/homeassistant/text_sensor/homeassistant_text_sensor.h>

// using namespace homeassistant;

namespace esphome {
  namespace jura_coffee {

    class JuraCoffee : public PollingComponent, public uart::UARTDevice {

      public:
        JuraCoffee();

        std::string tray_status
        std::string tank_status;

        String cmd2jura(String outbytes);

        void setup() override;
        void update() override;
        void loop() override {}

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

    };

  }
}
