# The module with the air quality sensor SGP41
Check the air you breathe. Thanks to our module with SGP41, a chip for evaluating air quality based on VOC and NOx, you can measure and record the measured data online and switch a fan-type actuator based on it.

![Assembled module](https://github.com/LaskaKit/SGP4x-Gas-Sensor/blob/main/img/1-11.jpg)

The SGP41 chip from Sensirion is one of the best on the market, we have designed and manufactured a simple module that you can plug into any board and it doesn't have to be our development kit with [ESP32-C3 LPkit](https://www.laskakit.cz/laskkit-esp-12-board/?variantId=10482), a [simple programmable kit with ESP32](https://www.laskakit.cz/laskakit-esp32-devkit/?variantId=11481) or a [kit with ESP32 and LAN](https://www.laskakit.cz/laskakit-esplan-esp32-lan8720a-max485-poe/?variantId=12167).

The module with SGP41 has two through-plug connectors so you can connect one to the development board and connect one of our other modules to the other - [SHT40 (temperature/humidity)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/), [BME280 (temperature, humidity, atmospheric pressure)](https://www.laskakit.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/), [SCD41 (CO2, temperature, humidity)](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/).

You can, of course, plug a female dupont connector into the module and connect it anywhere - [Arduino](https://www.laskakit.cz/arduino-2/), Raspberry Pi, [Rock Pi](https://www.laskakit.cz/radxa-rock-pi-4-b--b4e32-4gb-ram-32gb-emmc/) and more.

The I2C address is fixed and set to 0x59.

On the TOP side, here is solder bridge what connects pull-up resistors on power supply and I2C bus.

![Assembled module - bottom view](https://github.com/LaskaKit/SGP4x-Gas-Sensor/blob/main/img/3-10.jpg)

## SGP41
Minimum voltage is 1.7V</br>
The maximum is 3.6V.</br>
Consumption is 34uA in idle mode, during measurement the average consumption is 3mA</br>

Supported Arduino library </br>
[https://github.com/Sensirion/arduino-i2c-sgp41](https://github.com/Sensirion/arduino-i2c-sgp41)</br>
