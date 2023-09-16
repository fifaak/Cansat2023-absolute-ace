#include <SPI.h>
#include <LoRa.h>
#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif

#include <Wire.h>
#include "getValue.h"
#include "initWifi.h"
// #include "ifttt.h"
//const char* ssid     = "hotspot";
//const char* password = "12345678";

String incoming = "";
String bme280 = "";
// String gyro = "";
// String gps = "";

void setup() {
  Serial.begin(9600);
  while (!Serial);
  LoRa.setPins(5, 14, 2);
  Serial.println("LoRa Receiver");
//  LoRa.setSpreadingFactor(9);
//  LoRa.setSignalBandwidth(125E3);
  
  if (!LoRa.begin(920E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  initWifi();
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      incoming += (char)LoRa.read();
      
    }
    // String valx = getValue(incoming, ',', 0);
    // String valy = getValue(incoming, ',', 1);
    // String valz = getValue(incoming, ',', 2); 
    String hum = getValue(incoming, ',', 3); 
    String pha = getValue(incoming, ',', 4); 
    String alt = getValue(incoming, ',', 5);
    String tempC = getValue(incoming, ',', 6);
    // String latitude = getValue(incoming, ',', 7);
    // String longtitude = getValue(incoming, ',', 8);

    // gyro = gyro + "valx: " + valx + "valy: " + valy + "valz: " + valz;
    // bme280 = bme280 + "Hum: " + hum + "pha: " + pha + "alt: " + alt + "tempC: " + tempC;
    // gps = gps + latitude + "," + longtitude;
    
    // Serial.print(valx);
    // Serial.print(",");
    // Serial.print(valy);
    // Serial.print(",");
    // Serial.print(valz);
    // Serial.print(",");
    // Serial.print(hum);
    // Serial.print(",");
    // Serial.print(pha);
    // Serial.print(",");
    // Serial.print(alt);
    // Serial.print(",");
    // Serial.print(tempC);
    // Serial.print(",");
    // Serial.print(latitude);
    // Serial.print(",");
    // Serial.print(longtitude);
    // print RSSI of packet
    // Serial.print("' with RSSI ");
    // Serial.println(LoRa.packetRssi());
    //Serial.println(incoming);
    // makeIFTTTRequest(gyro,bme280,gps);
    // makeIFTTTRequest2(gyro,bme280,gps);
    // incoming = "";
    // gyro = ""; 
    bme280 = "";  
    // gps = "";
  }
  
}
