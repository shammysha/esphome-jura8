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

LeftTopButton = jura_coffee_ns.class_("LeftTopButton", button.Button)
LeftMiddleButton = jura_coffee_ns.class_("LeftMiddleButton", button.Button)
LeftBottomButton = jura_coffee_ns.class_("LeftBottomButton", button.Button)
RightTopButton = jura_coffee_ns.class_("RightTopButton", button.Button)
RightMiddleButton = jura_coffee_ns.class_("RightMiddleButton", button.Button)
RightBottomButton = jura_coffee_ns.class_("RightBottomButton", button.Button)


CONF_LEFT_TOP = "left_top"
CONF_LEFT_MIDDLE = "left_middle"
CONF_LEFT_BOTTOM = "left_bottom"
CONF_RIGHT_TOP = "right_top"
CONF_RIGHT_MIDDLE = "right_middle"
CONF_RIGHT_BOTTOM = "right_bottom"

ICON_LEFT_TOP = "mdi:arrow-top-left-bold-box-outline"
ICON_LEFT_MIDDLE = "mdi:arrow-left-bold-box-outline"
ICON_LEFT_BOTTOM = "mdi:arrow-bottom-left-bold-box-outline"
ICON_RIGHT_TOP = "mdi:arrow-top-right-bold-box-outline"
ICON_RIGHT_MIDDLE = "mdi:arrow-right-bold-box-outline"
ICON_RIGHT_BOTTOM = "mdi:arrow-bottom-right-bold-box-outline"

CONFIG_SCHEMA = {
    cv.GenerateID(CONF_JURA_ID): cv.use_id(JuraCoffee),
    
    cv.Optional(CONF_LEFT_TOP): button.button_schema(
        LeftTopButton,
        icon=ICON_LEFT_TOP
    ),
    cv.Optional(CONF_LEFT_MIDDLE): button.button_schema(
        LeftMiddleButton,
        icon=ICON_LEFT_MIDDLE
    ),
    cv.Optional(CONF_LEFT_BOTTOM): button.button_schema(
        LeftBottomButton,
        icon=ICON_LEFT_BOTTOM
    ),
    cv.Optional(CONF_RIGHT_TOP): button.button_schema(
        RightTopButton,
        icon=ICON_RIGHT_TOP
    ),
    cv.Optional(CONF_RIGHT_MIDDLE): button.button_schema(
        RightMiddleButton,
        icon=ICON_RIGHT_MIDDLE
    ),
    cv.Optional(CONF_RIGHT_BOTTOM): button.button_schema(
        RightBottomButton,
        icon=ICON_RIGHT_BOTTOM
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
