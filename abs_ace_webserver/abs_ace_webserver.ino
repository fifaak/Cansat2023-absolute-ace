
//=====================================
//ESP32 WebSocket Server: BME280 Sensor
//=====================================
#include <SPI.h>
#include <LoRa.h>
// #include <WiFi.h>
#include <Arduino.h>
#include <Wire.h>
#include <WebServer.h>
#include <WebSocketsServer.h>
#include "SparkFunBME280.h"
#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif

//-----------------------------------------------
BME280 bme;
const int SCLpin = 40; //ส่วนที่เพิ่ม
const int SDApin = 41; //ส่วนที่เพิ่ม
//-----------------------------------------------
const char* ssid = "12345678";
const char* password = "1212312121";
unsigned long previousMillis = 0;
unsigned long interval = 3000;

//-----------------------------------------------
WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);
//-----------------------------------------------
String JSONtxt;
String incoming = "";
String bme280 = "";
//-----------------------------------------------
#include "webpage.h"
#include "functions.h"
#include "getValue.h"
//====================================================================
void initWiFi(){
          WiFi.disconnect(true);

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

    while (!Serial);
  LoRa.setPins(5, 14, 2);

  Serial.println("LoRa Receiver");
    if (!LoRa.begin(920.24E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  initWiFi();
  server.on("/",handleRoot);
  server.begin();
  webSocket.begin();
}
//====================================================================
void loop() 
{
    unsigned long currentMillis = millis();
  int packetSize = LoRa.parsePacket();
 if (WiFi.status() != WL_CONNECTED){
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    WiFi.reconnect();
    //previousMillis = currentMillis;
  }


if (packetSize) {


    // read packet
    while (LoRa.available()) {
      incoming += (char)LoRa.read();
      
    }

   //gyro
   
    String AXISXvalString = getValue(incoming,',',0);
    String AXISYvalString = getValue(incoming,',',1);
   String ACCXvalString = getValue(incoming,',',2);
   String ACCYvalString = getValue(incoming,',',3);

    String HUMvalString = getValue(incoming, ',', 4); 
    String PRESvalString = getValue(incoming, ',', 5); 
    String ALTvalString = getValue(incoming, ',', 6);
    String TEMPvalString = getValue(incoming, ',', 7);
    

    //gps
    String LATvalString = getValue(incoming,',',8);
    String LONGvalString = getValue(incoming,',',9);

    String SECvalString = getValue(incoming,',',10);
 


    // bme280 = "";  
  webSocket.loop(); server.handleClient();
  //-----------------------------------------------

  JSONtxt  = "{\"TEMP\":\""+TEMPvalString+"\",";
  JSONtxt += "\"HUM\":\""+HUMvalString+"\",";
  JSONtxt += "\"PRES\":\""+PRESvalString+"\",";
  JSONtxt += "\"ALT\":\""+ALTvalString+"\",";
    JSONtxt += "\"LAT\":\""+LATvalString+"\",";
  JSONtxt += "\"LONG\":\""+LONGvalString+"\",";
  JSONtxt += "\"AXISX\":\""+AXISXvalString+"\",";
    JSONtxt += "\"AXISY\":\""+AXISYvalString+"\",";
  JSONtxt += "\"ACCX\":\""+ACCXvalString+"\",";
   JSONtxt += "\"ACCY\":\""+ACCYvalString+"\",";
      JSONtxt += "\"SEC\":\""+SECvalString+"\"}";

  webSocket.broadcastTXT(JSONtxt);
  Serial.println(SECvalString);
  incoming = "";
  }

}
