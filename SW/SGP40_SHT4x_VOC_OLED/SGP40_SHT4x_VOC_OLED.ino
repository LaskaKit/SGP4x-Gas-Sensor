/*
* This example code for SGP40 Air Quality Sensor plus Temperature and Humidity SHT41 module 
* is used with ESP32 LPkit board.
* ESP32-LPkit reads data from SGP40 sensor and use Temperature and Humidity SHT41 module to calculate VOC index
* and shows on OLED display
*
* SDA - GPIO21
* SCL - GPIO22
*
* Made by (c) laskakit.cz 2023
*
* Libraries
* https://github.com/adafruit/Adafruit_SGP40 Example is used
* https://github.com/adafruit/Adafruit_SHT4X
* https://github.com/adafruit/Adafruit-GFX-Library
* https://github.com/adafruit/Adafruit_SH110X
*/

#include <SPI.h>
#include <Wire.h>
#include "Adafruit_SGP40.h"
#include "Adafruit_SHT4x.h"
#include <Adafruit_GFX.h>     // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SH110X.h>  // https://github.com/adafruit/Adafruit_SH110X

#define i2c_Address 0x3c

Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1); //Nastavý display
Adafruit_SGP40 sgp;
Adafruit_SHT4x sht4 = Adafruit_SHT4x();

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); } // Wait for serial console to open!

  Serial.println("SGP40 test with SHT41 compensation");

  if (! sgp.begin()){
    Serial.println("SGP40 sensor not found :(");
    while (1);
  }

 if (! sht4.begin()) {
    Serial.println("SHT4x not found");
    Serial.println("Check the connection");
    while (1) delay(1);
  }
 
  sht4.setPrecision(SHT4X_HIGH_PRECISION); // highest resolution
  sht4.setHeater(SHT4X_NO_HEATER); // no heater

  Serial.print("Found SHT4x + SGP40 serial #");
  Serial.print(sgp.serialnumber[0], HEX);
  Serial.print(sgp.serialnumber[1], HEX);
  Serial.println(sgp.serialnumber[2], HEX);

  delay(250);
  
  display.begin(i2c_Address, true); 
  display.clearDisplay(); 
  display.setTextColor(SH110X_WHITE); 
  display.setTextSize(1); 
}

int counter = 0;
void loop() {
  uint16_t sraw;
  int32_t voc_index;
  
  sensors_event_t humidity, temp; // temperature and humidity variables
  sht4.getEvent(&humidity, &temp);

  float t = temp.temperature;
  Serial.print("Temp *C = "); Serial.print(t); Serial.print("\t\t");
  float h = humidity.relative_humidity;
  Serial.print("Hum. % = "); Serial.println(h);

  sraw = sgp.measureRaw(t, h);
  Serial.print("Raw measurement: ");
  Serial.println(sraw);

  voc_index = sgp.measureVocIndex(t, h);
  
  if(voc_index == 0) {
     Serial.println("Voc Index: Calibrating...");                       //colibrating the sensor
  } else {
    Serial.print("Voc Index: ");
    Serial.println(voc_index);       //Zobrazí na displeji Voc Index
  }

  display.setCursor(0,0);
  if(voc_index == 0) {
    display.println("Calibrating...");                       //colibrating the sensor
  } else {
    display.println((String)"Voc Index: "+ voc_index);       //Zobrazí na displeji Voc Index
  }

  display.display(); 
  delay(1000);
  display.clearDisplay();
}