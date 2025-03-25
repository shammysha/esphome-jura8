#include "right_bottom_button.h"

namespace esphome {
  namespace jura_coffee {

    void RightBottomButton::press_action() {
      this->parent_->cmd2jura("FA:09");
    }

  }
}
