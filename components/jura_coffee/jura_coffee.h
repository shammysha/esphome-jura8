#include "esphome.h"
// #include <esphome/components/homeassistant/text_sensor/homeassistant_text_sensor.h>

// using namespace homeassistant;

namespace esphome {
namespace jura_coffee {

class JuraCoffee: public PollingComponent, public UARTDevice {
    TextSensor *xsensor6 { nullptr };
    TextSensor *xsensor7 { nullptr };


  public:
    JuraCoffee(UARTComponent *parent, TextSensor *sensor6, TextSensor *sensor7) : UARTDevice(parent), xsensor6(sensor6), xsensor7(sensor7) {}

    std::string tray_status
    std::string tank_status;

    String cmd2jura(String outbytes);

    void setup() override;
    void loop() override {}
    void update() override;

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

}}
