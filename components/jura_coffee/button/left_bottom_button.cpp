#include "left_bottom_button.h"

namespace esphome {
  namespace jura_coffee {

    void LeftBottomButton::press_action() {
      this->parent_->cmd2jura("FA:06");
    }

  }
}
