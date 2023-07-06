/*
* This example code for SGP40 Air Quality Sensor 
* is used with ESP32 LPkit board.
* ESP32-LPkit reads VOC index from SGP40 sensor 
* and shows on serial monitor
*
* SDA - GPIO21
* SCL - GPIO22
*
* Made by (c) laskakit.cz 2023
*
* Libraries
* https://github.com/adafruit/Adafruit_SGP40 Example is used
*/

#include <Wire.h>
#include "Adafruit_SGP40.h"

Adafruit_SGP40 sgp;


void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); } // Wait for serial console to open!

  Serial.println("SGP40 test");

  if (! sgp.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.print("Found SGP40 serial #");
  Serial.print(sgp.serialnumber[0], HEX);
  Serial.print(sgp.serialnumber[1], HEX);
  Serial.println(sgp.serialnumber[2], HEX);
}

int counter = 0;
void loop() {
  uint16_t raw;
  
  raw = sgp.measureRaw();

  Serial.print("Measurement: ");
  Serial.println(raw);
  delay(1000);
}