import esphome.codegen as cg
from esphome.components import switch
import esphome.config_validation as cv
from esphome.const import (
    DEVICE_CLASS_SWITCH,
    CONF_POWER
)
from .. import (
    JuraCoffee, 
    jura_coffee_ns,
    CONF_JURA_ID    
)

PowerSwitch = jura_coffee_ns.class_("PowerSwitch", switch.Switch)

CONFIG_SCHEMA = ({
    cv.GenerateID(CONF_JURA_ID): cv.use_id(JuraCoffee),
    cv.Optional(CONF_POWER): switch.switch_schema(
        PowerSwitch,
        device_class=DEVICE_CLASS_SWITCH
    )    
})

async def to_code(config):
    jura_component = await cg.get_variable(config[CONF_JURA_ID])
    if power := config.get(CONF_POWER):
        sw = await switch.new_switch(power)
        await cg.register_parented(sw, config[CONF_JURA_ID])
        cg.add(jura_component.set_power_switch(sw))        
                
