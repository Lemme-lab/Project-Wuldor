 #include "WiFi.h"
 #include "ESPAsyncWebServer.h"
 #include "SPIFFS.h"
 #include <Arduino.h>

 const int ledPin = 2;
 String ledState;


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
   AsyncWebServer server(80); 
   const char* ssid = "ssid";
   const char* password = "pwd";
   Serial.begin(9600);
   pinMode(ledPin, OUTPUT);

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

   server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
     digitalWrite(ledPin, LOW);    
     request->send(SPIFFS, "/index.html", String(), false, processor);
   });
   server.begin();
   } 