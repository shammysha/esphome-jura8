import esphome.codegen as cg
from esphome.components import button
import esphome.config_validation as cv
from esphome.const import (
    DEVICE_CLASS_RESTART,
    ENTITY_CATEGORY_DIAGNOSTIC,
    ENTITY_CATEGORY_CONFIG,
    ICON_RESTART,
    ICON_RESTART_ALERT,
    ICON_DATABASE,
)
from .. import (
    JuraCoffee, 
    jura_coffee_ns,
    CONF_JURA_ID    
)

AUTO_LOAD = ["jura_coffee"]

JuraCoffeeLeftTopButton = jura_coffee_ns.class_("JuraCoffeeLeftTopButton", button.Button)
JuraCoffeeLeftMiddleButton = ld2450_ns.class_("JuraCoffeeLeftMiddleButton", button.Button)
JuraCoffeeLeftBottomButton = ld2450_ns.class_("JuraCoffeeLeftBottomButton", button.Button)
JuraCoffeeRightTopButton = jura_coffee_ns.class_("JuraCoffeeRightTopButton", button.Button)
JuraCoffeeRightMiddleButton = ld2450_ns.class_("JuraCoffeeRightMiddleButton", button.Button)
JuraCoffeeRightBottomButton = ld2450_ns.class_("JuraCoffeeRightBottomButton", button.Button)


CONF_LEFT_TOP = "left_top"
CONF_LEFT_MIDDLE = "left_middle"
CONF_LEFT_BOTTOM = "left_bottom"
CONF_RIGHT_TOP = "right_top"
CONF_RIGHT_MIDDLE = "right_middle"
CONF_RIGHT_BOTTOM = "right_bottom"

CONFIG_SCHEMA = {
    cv.GenerateID(CONF_JURA_ID): cv.use_id(JuraCoffee),
    
    cv.Optional(CONF_LEFT_TOP): button.button_schema(
        JuraCoffeeLeftTopButton,
        icon=ICON_RESTART_ALERT,
    ),
    cv.Optional(CONF_LEFT_MIDDLE): button.button_schema(
        JuraCoffeeLeftMiddleButton,
        icon=ICON_RESTART_ALERT,
    ),
    cv.Optional(CONF_LEFT_BOTTOM): button.button_schema(
        JuraCoffeeLeftBottomButton,
        icon=ICON_RESTART_ALERT,
    ),
    cv.Optional(CONF_RIGHT_TOP): button.button_schema(
        JuraCoffeeRightTopButton,
        icon=ICON_RESTART_ALERT,
    ),
    cv.Optional(CONF_RIGHT_MIDDLE): button.button_schema(
        JuraCoffeeRightMiddleButton,
        icon=ICON_RESTART_ALERT,
    ),
    cv.Optional(CONF_RIGHT_BOTTOM): button.button_schema(
        JuraCoffeeRightBottomButton,
        icon=ICON_RESTART_ALERT,
    ),
}


async def to_code(config):
    jura_component = await cg.get_variable(config[CONF_JURA_ID])
    if left_top := config.get(CONF_LEFT_TOP):
        btn = await button.new_button(left_top)
        cg.add(jura_component.set_left_top_button(btn))        
    
    if left_middle := config.get(CONF_LEFT_MIDDLE):
        btn = await button.new_button(left_middle)
        cg.add(jura_component.set_left_middle_button(btn))   
    
    if left_bottom := config.get(CONF_LEFT_BOTTOM):
        btn = await button.new_button(left_bottom)
        cg.add(jura_component.set_left_bottom_button(btn))   
    
    if right_top := config.get(CONF_RIGHT_TOP):
        btn = await button.new_button(right_top)
        cg.add(jura_component.set_right_top_button(btn))        
    
    if right_middle := config.get(CONF_RIGHT_MIDDLE):
        btn = await button.new_button(right_middle)
        cg.add(jura_component.set_right_middle_button(btn))   
    
    if right_bottom := config.get(CONF_RIGHT_BOTTOM):
        btn = await button.new_button(right_bottom)
        cg.add(jura_component.set_right_bottom_button(btn))            
