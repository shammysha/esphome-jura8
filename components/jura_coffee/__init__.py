import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import (
    CONF_ID
)

DEPENDENCIES = ["uart"]
MULTI_CONF = True

jura_coffee_ns = cg.esphome_ns.namespace("jura_coffee")

JuraCoffee = jura_coffee_ns.class_("JuraCoffee", cg.PollingComponent, uart.UARTDevice)


CONF_JURA_ID = "jura_id"

MULTI_CONF = True
CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(JuraCoffee),
    }
)

CONFIG_SCHEMA = cv.All(
    CONFIG_SCHEMA.extend(uart.UART_DEVICE_SCHEMA).extend(cv.COMPONENT_SCHEMA)
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)
