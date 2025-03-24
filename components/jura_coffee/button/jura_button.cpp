#include "jura_button.h"

namespace esphome {
  namespace jura_coffee {

    void JuraCofeeLeftTopButton::press_action() {
      this->parent_->cmd2jura("FA:04");
    }

    void JuraCofeeLeftMiddleButton::press_action() {
        this->parent_->cmd2jura("FA:05");
    }

    void JuraCofeeLeftBottomButton::press_action() {
      this->parent_->cmd2jura("FA:06");
    }

    void JuraCofeeRightTopButton::press_action() {
      this->parent_->cmd2jura("FA:07");
    }

    void JuraCofeeRightMiddleButton::press_action() {
      this->parent_->cmd2jura("FA:08");
    }

    void JuraCofeeRightBottomButton::press_action() {
      this->parent_->cmd2jura("FA:09");
    }

  }
}
