#include <Arduino.h>
#include "Main_Header.h"

const char* ssid = "ssid";
const char* password = "pwd";


const int ledPin = 2;
AsyncWebServer server = 80;


 void web(){

   Serial.begin(9600);

   if(!SPIFFS.begin(true)){
     Serial.println("An Error has occurred while mounting SPIFFS");
     return;
   }

   WiFi.begin(ssid, password);
    Serial.println("");
    Serial.print("Connecting to WiFi..");
   while (WiFi.status() != WL_CONNECTED) {
     delay(1000);
     Serial.print(".");
   }

   Serial.println(WiFi.localIP());
   server.begin();
   } 