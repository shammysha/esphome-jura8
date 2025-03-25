#include "jura_button.h"
#include "esphome/core/log.h"

namespace esphome {
  namespace jura_coffee {

    void LeftTopButton::press_action() {
      this->parent_->cmd2jura("FA:04");
    }

    void LeftMiddleButton::press_action() {
      ESP_LOGD("main", "Sending command FA:05");
      this->parent_->cmd2jura("FA:05");
    }

    void LeftBottomButton::press_action() {
      this->parent_->cmd2jura("FA:06");
    }

    void RightTopButton::press_action() {
      this->parent_->cmd2jura("FA:07");
    }

    void RightMiddleButton::press_action() {
      this->parent_->cmd2jura("FA:08");
    }

    void RightBottomButton::press_action() {
      this->parent_->cmd2jura("FA:09");
    }

  }
}
