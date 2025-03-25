#include "right_top_button.h"

namespace esphome {
  namespace jura_coffee {

    void RightTopButton::press_action() {
      this->parent_->cmd2jura("FA:07");
    }

  }
}
