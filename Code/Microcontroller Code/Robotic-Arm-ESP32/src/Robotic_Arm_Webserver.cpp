/*#include <Arduino.h>
#include "Main_Header.h"

const char* ssid = "ssid";
const char* password = "pwd";


const int ledPin = 2;
String ledState;
AsyncWebServer server = 80;

String processor(const String& var){
   Serial.println(var);
   if(var == "STATE"){
     if(digitalRead(ledPin)){
       ledState = "ON";
     }
     else{
       ledState = "OFF";
     }
     Serial.print(ledState);
     return ledState;
   }
   return String();
 }


 void web(){

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
   Serial.println(" ");
   Serial.println(WiFi.localIP());

   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
     request->send(SPIFFS, "/index.html", String(), false, processor);
   });


   server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
     request->send(SPIFFS, "/style.css", "text/css");
   });


   server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(ledPin, HIGH);    
     request->send(SPIFFS, "/index.html", String(), false, processor);
   });

   // Route to set GPIO to LOW
   server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(ledPin, LOW);    
     request->send(SPIFFS, "/index.html", String(), false, processor);
   });

   server.begin();
   } */