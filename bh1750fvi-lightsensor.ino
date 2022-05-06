/*
  Connecting the sensor to a Arduino UNO / Nano:
  VCC  <-> 3V3
  GND  <-> GND
  SDA  <-> A4/SDA 
  SCL  <-> A5/SCL
*/

#include <BH1750FVI.h>

BH1750FVI LightSensor(BH1750FVI::k_DevModeOneTimeHighRes);

void setup() 
{
  Serial.begin(9600);
  Serial.setTimeout(100);
  LightSensor.begin();  
}

void loop()
{
  while (Serial.available() == 0) {
    delay(100);
  }
  
  String input = Serial.readString();
  if (input == "GET") {
    uint16_t lux = LightSensor.GetLightIntensity();
    Serial.println(lux);
  }
}
