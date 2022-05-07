/*
  BH1750FVI と Arduino UNO/Nano の接続:
  VCC  <-> 3V3 or 5V
  GND  <-> GND
  SDA  <-> A4/SDA 
  SCL  <-> A5/SCL
*/

#include <BH1750.h>

BH1750 lightSensor;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);

  Wire.begin();
  lightSensor.begin(BH1750::ONE_TIME_HIGH_RES_MODE);
}

void loop() {
  while (!Serial.available()) {
    delay(50);
  }
  
  String input = Serial.readString();
  if (input.startsWith("GET")) {
    lightSensor.configure(BH1750::ONE_TIME_HIGH_RES_MODE);
    while (!lightSensor.measurementReady(true)) {
      delay(10);
    }

    float lux = lightSensor.readLightLevel();
    Serial.println(lux);
  }
}
