#include "left_top_button.h"

namespace esphome {
  namespace jura_coffee {

    void LeftTopButton::press_action() {
      this->parent_->cmd2jura("FA:04");
    }

  }
}
