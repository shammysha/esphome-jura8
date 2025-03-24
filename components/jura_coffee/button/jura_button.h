#pragma once

#include "esphome/components/button/button.h"
#include "../jura_coffee.h"

namespace esphome {
  namespace jura_coffee {

    class JuraCofeeLeftTopButton: public button::Button, public Parented<JuraCoffee> {
      public:
        JuraCofeeLeftTopButton() = default;

      protected:
        void press_action() override;
    };

    class JuraCofeeLeftMiddleButton: public button::Button, public Parented<JuraCoffee> {
      public:
        JuraCofeeLeftMiddleButton() = default;

      protected:
        void press_action() override;
    };

    class JuraCofeeLeftBottomButton: public button::Button, public Parented<JuraCoffee> {
      public:
        JuraCofeeLeftBottomButton() = default;

      protected:
        void press_action() override;
    };

    class JuraCofeeRightTopButton: public button::Button, public Parented<JuraCoffee> {
      public:
        JuraCofeeRightTopButton() = default;

      protected:
        void press_action() override;
    };

    class JuraCofeeRightMiddleButton: public button::Button, public Parented<JuraCoffee> {
      public:
        JuraCofeeRightMiddleButton() = default;

      protected:
        void press_action() override;
    };

    class JuraCofeeRightBottomButton: public button::Button, public Parented<JuraCoffee> {
      public:
        JuraCofeeRightBottomButton() = default;

      protected:
        void press_action() override;
    };

  }
}
