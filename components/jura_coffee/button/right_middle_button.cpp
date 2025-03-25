#include "right_middle_button.h"

namespace esphome {
  namespace jura_coffee {

    void RightMiddleButton::press_action() {
      this->parent_->cmd2jura("FA:08");
    }

  }
}
