#include <Wire.h>
#include <Arduino.h>
#include "SparkFunBME280.h"
#include <SPI.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <TinyGPSPlus.h>
const char *gpsStream =
  "$GPRMC,045103.000,A,3014.1984,N,09749.2872,W,0.67,161.46,030913,,,A*7C\r\n"
  "$GPGGA,045104.000,3014.1985,N,09749.2873,W,1,09,1.2,211.6,M,-22.5,M,,0000*62\r\n"
  "$GPRMC,045200.000,A,3014.3820,N,09748.9514,W,36.88,65.02,030913,,,A*77\r\n"
  "$GPGGA,045201.000,3014.3864,N,09748.9411,W,1,10,1.2,200.8,M,-22.5,M,,0000*6C\r\n"
  "$GPRMC,045251.000,A,3014.4275,N,09749.0626,W,0.51,217.94,030913,,,A*7D\r\n"
  "$GPGGA,045252.000,3014.4273,N,09749.0628,W,1,09,1.3,206.9,M,-22.5,M,,0000*6F\r\n";

TinyGPSPlus gps;
BME280 bme;
Adafruit_MPU6050 mpu;

unsigned long delayTime;

void setup() {
    Serial.begin(115200);
    Wire.begin();    
    bme.setI2CAddress(0x76);
    delayTime = 1000;
    bme.beginI2C();
    mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    Serial.println();
}


void loop() { 
    printValues();
}


void printValues() {
  Serial.print("Humidity: ");
  Serial.print(bme.readFloatHumidity(), 0);

  Serial.print(" Pressure: ");
  Serial.print(bme.readFloatPressure(), 0);

  Serial.print(" Alt: ");
  Serial.print(bme.readFloatAltitudeFeet(), 1);

  Serial.print(" Temp: ");
  Serial.print(bme.readTempC(), 2);

  Serial.println();
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  Serial.print("AccelX:");
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print("AccelY:");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.print("AccelZ:");
  Serial.print(a.acceleration.z);
  Serial.print(", ");
  Serial.print("GyroX:");
  Serial.print(g.gyro.x);
  Serial.print(",");
  Serial.print("GyroY:");
  Serial.print(g.gyro.y);
  Serial.print(",");
  Serial.print("GyroZ:");
  Serial.print(g.gyro.z);
  Serial.println("");


    if (gps.location.isValid())
    {
      Serial.print(gps.location.lat(), 15);
      Serial.print(F(","));
      Serial.print(gps.location.lng(), 15);
    }
    Serial.println();





  delay(1000);
    
}
