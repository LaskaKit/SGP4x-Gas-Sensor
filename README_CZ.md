# Modul pro měření kvality ovzduší s SGP41
Hlídej vzduch, který dýcháš. Díky našemu modulu s SGP41, čipem pro vyhodnocení kvality vzduchu na základě VOC a NOx, můžeš měřit a online zaznamenávat naměřená data a na jejich základě spínat akční prvek typu ventilátor.

![Osazený modul](https://github.com/LaskaKit/SGP4x-Gas-Sensor/blob/main/img/1-11.jpg)

Čip SGP41 od firmy Sensirion patří mezi ty nejkvalitnější na trhu, my navrhli a vyrobili jednoduchý modul, který můžeš připojit do jakékoliv desky a nemusí to být zrovna náš vývojový kit s [ESP32-C3 LPkit](https://www.laskakit.cz/laskkit-esp-12-board/?variantId=10482), jednoduše [programovatelný kit s ESP32](https://www.laskakit.cz/laskakit-esp32-devkit/?variantId=11481) nebo [kit s ESP32 a LAN](https://www.laskakit.cz/laskakit-esplan-esp32-lan8720a-max485-poe/?variantId=12167).

Modul s SGP41 má dva průchozí uŠup konektory a tak jeden můžeš připojit do vývojové desky, do druhého připojit jeden z našich dalších modulů - [SHT40 (teplota/vlhkost)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/), [BME280 (teplota, vlhkost, atmosférický tlak)](https://www.laskakit.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/), [SCD41 (CO2, teplota, vlhkost)](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/).

Na modul můžeš samozřejmě zapájet hřebínek a zapojit kamkoliv - [Arduino](https://www.laskakit.cz/arduino-2/), Raspberry Pi, [Rock Pi](https://www.laskakit.cz/radxa-rock-pi-4-b--b4e32-4gb-ram-32gb-emmc/) a další. 

Adresa čidla je fixní a čidlo tak najdeš na adrese 0x59.

Na přední straně je pájecí most, který připojuje pull-up rezistory na I2C sběrnici. 

![Osazený modul - zadní strana](https://github.com/LaskaKit/SGP4x-Gas-Sensor/blob/main/img/3-10.jpg)

## SGP41
Minimální napětí je 1.7V</br>
Maximální pak 3.6V.</br>
Spotřeba je 34uA v idle režimu, během měření je průměrná spotřeba 3mA</br>

Mezi podporované knihovny patří </br>
[https://github.com/Sensirion/arduino-i2c-sgp41](https://github.com/Sensirion/arduino-i2c-sgp41)</br>
