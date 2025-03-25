#pragma once

#include "esphome/components/switch/switch.h"
#include "../jura_coffee.h"

namespace esphome {
  namespace jura_coffee {

    class PowerSwitch : public switch_::Switch, public Parented<JuraCoffee> {
      public:
        PowerSwitch() = default;

      protected:
        void write_state(bool state) override;
    };

  }
}
