# binary-clock
This is my first hardware project. After learning how to use the arduino, I decided to try to make my own binary clock.
I designed the clock, wrote the firmware, created the schematics and board layout, and etched the PCB.

### BOM

* 1x Atmel ATMega328
* 2x 10uF Capacitor
* 2x 22pF Capacitor
* 10x 220ohm Resistor
* 1x 1kohm Resistor
* 2x 10kohm Resistor
* 1x 16Mhz XTAL
* 3x Push Button Switch
* 1x Power Jack
* 1x 5v Regulator

### Design

Most binary clocks available use 2 bytes for each hour, minute, and seconds and I did not like that approach, so I designed my own clock. However the clock does not have an `AM` or `PM` indicator.

| Hour               |                   | Minute             |                   |                    |
| :----------------: | :---------------: | :----------------: | :---------------: | :----------------: |
| on:`8`, off:`0` | on:`4`, off:`0` | on:`32`, off:`0` | on:`16`, off:`0` | on:`8`, off:`0` |
| on:`2`, off:`0`  | on:`1`, off:`0` | on:`4`, off:`0`  | on:`2`, off:`0`  | on:`1`, off:`0` |


Example: `10:35`


| Hour|     | Minute||   |
|:----:|:----:|:--:|:--:|:--:|
| `on` | off | `on` | off  | off  |
| `on` | off  | off  | `on` | `on` |

Hour: `8 + 2` = `10`
Minute: `32 + 2 + 1` = `35`
