import esphome.codegen as cg
from esphome.components import text_sensor
import esphome.config_validation as cv
from . import CONF_JURA_ID, JuraCoffee

DEPENDENCIES = ["JuraCoffee"]

CONF_TANK = "tank"
CONF_TRAY = "tray"

CONFIG_SCHEMA = {
    cv.GenerateID(CONF_LD2450_ID): cv.use_id(JuraCoffee),
    cv.Optional(CONF_TANK): text_sensor.text_sensor_schema(),
    cv.Optional(CONF_TRAY): text_sensor.text_sensor_schema(),
}


async def to_code(config):
    jura_coffee = await cg.get_variable(config[CONF_LD2450_ID])
    if tank := config.get(CONF_TANK):
        sens = await text_sensor.new_text_sensor(tank)
        cg.add(ld2450_component.set_tank_text_sensor(sens))
    if tray := config.get(CONF_TRAY):
        sens = await text_sensor.new_text_sensor(tray)
        cg.add(ld2450_component.set_tray_text_sensor(sens))