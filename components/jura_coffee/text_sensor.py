import esphome.codegen as cg
from esphome.components import text_sensor
import esphome.config_validation as cv
from . import (
    JuraCoffee,
    jura_coffee_ns,
    CONF_JURA_ID 
)

AUTO_LOAD = ["jura_coffee"]

CONF_TANK = "tank"
CONF_TRAY = "tray"

CONFIG_SCHEMA = {
    cv.GenerateID(CONF_JURA_ID): cv.use_id(JuraCoffee),
    cv.Optional(CONF_TANK): text_sensor.text_sensor_schema(),
    cv.Optional(CONF_TRAY): text_sensor.text_sensor_schema(),
}


async def to_code(config):
    jura_component = await cg.get_variable(config[CONF_JURA_ID])
    if tank := config.get(CONF_TANK):
        sens = await text_sensor.new_text_sensor(tank)
        cg.add(jura_component.set_tank_text_sensor(sens))
    if tray := config.get(CONF_TRAY):
        sens = await text_sensor.new_text_sensor(tray)
        cg.add(jura_component.set_tray_text_sensor(sens))