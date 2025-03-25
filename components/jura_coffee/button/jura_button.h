#pragma once

#include "esphome/components/button/button.h"
#include "../jura_coffee.h"

namespace esphome {
  namespace jura_coffee {

    class LeftTopButton: public button::Button, public Parented<JuraCoffee> {
      public:
        LeftTopButton() = default;

      protected:
        void press_action() override;
    };

    class LeftMiddleButton : public button::Button, public Parented<JuraCoffee> {
      public:
        LeftMiddleButton() = default;

      protected:
        void press_action() override;
    };

    class LeftBottomButton : public button::Button, public Parented<JuraCoffee> {
      public:
        LeftBottomButton() = default;

      protected:
        void press_action() override;
    };

    class RightTopButton: public button::Button, public Parented<JuraCoffee> {
      public:
        RightTopButton() = default;

      protected:
        void press_action() override;
    };

    class RightMiddleButton: public button::Button, public Parented<JuraCoffee> {
      public:
        RightMiddleButton() = default;

      protected:
        void press_action() override;
    };

    class RightBottomButton: public button::Button, public Parented<JuraCoffee> {
      public:
        RightBottomButton() = default;

      protected:
        void press_action() override;
    };

  }
}
