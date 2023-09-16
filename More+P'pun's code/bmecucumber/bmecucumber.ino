#include <Wire.h>
#include <Arduino.h>
#include "SparkFunBME280.h"
BME280 mySensor;
const int SCLpin = 40; //ส่วนที่เพิ่ม
const int SDApin = 41; //ส่วนที่เพิ่ม

void setup()
{
  delay(3000);
  Serial.begin(115200);
  Serial.println("Reading basic values from BME280");

  Wire.begin(SDApin, SCLpin); //ส่วนที่เพิ่ม
    
  mySensor.setI2CAddress(0x76);
  if (mySensor.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while(1); //Freeze
  }
}

void loop()
{
  Serial.print("Humidity: ");
  Serial.print(mySensor.readFloatHumidity(), 0);

  Serial.print(" Pressure: ");
  Serial.print(mySensor.readFloatPressure(), 0);

  Serial.print(" Alt: ");
  //Serial.print(mySensor.readFloatAltitudeMeters(), 1);
  Serial.print(mySensor.readFloatAltitudeFeet(), 1);

  Serial.print(" Temp: ");
  //Serial.print(mySensor.readTempC(), 2);
  Serial.print(mySensor.readTempC(), 2);

  Serial.println();

  delay(50);
}
