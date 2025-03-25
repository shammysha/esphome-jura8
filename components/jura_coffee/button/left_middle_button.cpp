#include "left_middle_button.h"

namespace esphome {
  namespace jura_coffee {

    void LeftMiddleButton::press_action() {
        this->parent_->cmd2jura("FA:05");
    }

  }
}
