//=====================================
//ESP32 WebSocket Server: BME280 Sensor
//=====================================
#include <WiFi.h>
#include <Arduino.h>
#include <Wire.h>
#include <WebServer.h>
#include <WebSocketsServer.h>
#include "SparkFunBME280.h"

//-----------------------------------------------
BME280 bme;
const int SCLpin = 40; //ส่วนที่เพิ่ม
const int SDApin = 41; //ส่วนที่เพิ่ม
//-----------------------------------------------
const char* ssid = "Internet";
const char* password = "12345678";
unsigned long previousMillis = 0;
unsigned long interval = 3000;
//-----------------------------------------------
WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);
//-----------------------------------------------
String JSONtxt;
//-----------------------------------------------
#include "webpage.h"
#include "functions.h"

//====================================================================

void initWiFi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}




void setup()
{
  Serial.begin(9600);
  
Wire.begin(SDApin, SCLpin);
bme.setI2CAddress(0x76);
  //-----------------------------------------------
  bool status = bme.beginI2C();
  if (status == false)
  {
    Serial.println("BME280 sensor not found!");
    while(1);
  }
  //-----------------------------------------------
  initWiFi();
  server.on("/",handleRoot);
  server.begin();
  webSocket.begin();
}
//====================================================================
void loop() 
{
    unsigned long currentMillis = millis();

 if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) {
    Serial.print(millis());
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    WiFi.reconnect();
    previousMillis = currentMillis
    ;
  }




  webSocket.loop(); server.handleClient();
  //-----------------------------------------------
  String TEMPvalString = String(bme.readTempC(),1);
  String HUMvalString = String(bme.readFloatHumidity(),1);
  String PRESvalString = String(bme.readFloatPressure(),1);
  //-----------------------------------------------
  String POTvalString = String(float(analogRead(A0))/1170.0);
  String LDRvalString = String(analogRead(A3));
  //-----------------------------------------------
  JSONtxt  = "{\"TEMP\":\""+TEMPvalString+"\",";
  JSONtxt += "\"HUM\":\""+HUMvalString+"\",";
  JSONtxt += "\"PRES\":\""+PRESvalString+"\",";
  JSONtxt += "\"LDR\":\""+LDRvalString+"\",";
  JSONtxt += "\"POT\":\""+POTvalString+"\"}";
  webSocket.broadcastTXT(JSONtxt);
  delay(100);
}
