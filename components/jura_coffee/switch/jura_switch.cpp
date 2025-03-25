#include "jura_switch.h"

namespace esphome {
  namespace jura_coffee {

    void JuraCoffeePowerSwitch::write_state(bool state) {
      this->publish_state(state);

      if (state) {
        this->parent_->cmd2jura("AN:01");
      } else {
        this->parent_->cmd2jura("AN:02");
      }
    }

  }
}
