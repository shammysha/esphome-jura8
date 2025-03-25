#pragma once

#include "esphome/components/button/button.h"
#include "../jura_coffee.h"

namespace esphome {
  namespace jura_coffee {

    class RightMiddleButton: public button::Button, public Parented<JuraCoffee> {
      public:
        RightMiddleButton() = default;

      protected:
        void press_action() override;
    };

  }
}
