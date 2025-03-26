# esphome-jura8

Esphome component for JURA E8 Coffee Machine

Example:

```
substitutions:
  devicename: "jura-coffee"

external_components:
  - source:
      type: git
      url: https://github.com/shammysha/esphome-jura8
      ref: main
    components: [ jura_coffee ]
    refresh: 1s

uart:
  id: uart_bus
  tx_pin: D2
  rx_pin: D1
  baud_rate: 9600
  debug:  

jura_coffee:
  uart_id: uart_bus
  id: jura8

button:
  - platform: jura_coffee
    jura_id: jura8
    left_top:
      name: "${devicename} Left Top Button"
    left_middle:
      name: "${devicename} Left Middle Button"
    left_bottom:
      name: "${devicename} Left Bottom Button"    
    right_top:
      name: "${devicename} Right Top Button"
    right_middle:
      name: "${devicename} Right Middle Button"
    right_bottom:
      name: "${devicename} Right Bottom Button"        

switch:
  - platform: jura_coffee
    jura_id: jura8
    power:
      name: ${devicename}

text_sensor:
  - platform: jura_coffee
    jura_id: jura8
    tray:  
      name: "${devicename} Tray Status"        
    tank:  
      name: "${devicename} Tank Status"
```
