#pragma once

#include "esphome/components/button/button.h"
#include "../jura_coffee.h"

namespace esphome {
  namespace jura_coffee {

    class LeftBottomButton : public button::Button, public Parented<JuraCoffee> {
      public:
        LeftBottomButton() = default;

      protected:
        void press_action() override;
    };

  }
}
