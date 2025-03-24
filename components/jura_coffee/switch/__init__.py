import esphome.codegen as cg
from esphome.components import switch
import esphome.config_validation as cv
from esphome.const import (
    DEVICE_CLASS_POWER,
    CONF_POWER
)
from .. import (
    JuraCoffee, 
    jura_coffee_ns,
    CONF_JURA_ID    
)

AUTO_LOAD = ["jura_coffee"]

JuraCoffeePowerSwitch = jura_coffee_ns.class_("JuraCoffeePowerSwitch", switch.Switch)

CONFIG_SCHEMA = ({
    cv.GenerateID(CONF_JURA_ID): cv.use_id(JuraCoffee),
    cv.Optional(CONF_POWER): switch.switch_schema(
        JuraCoffeePowerSwitch,
        device_class=DEVICE_CLASS_POWER
    )    
})

async def to_code(config):
    jura_component = await cg.get_variable(config[CONF_JURA_ID])
    if power := config.get(CONF_POWER):
        s = await switch.new_switch(power)
        cg.add(jura_component.set_power_switch(power))        
                
