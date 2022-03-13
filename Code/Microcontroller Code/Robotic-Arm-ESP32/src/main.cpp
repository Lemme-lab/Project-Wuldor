#include <WiFi.h>

#include <HTTPClient.h>

const char * ssid = "Name";
const char * password = "pwd";


String serverName = "http://127.0.0.1:5500/Code/web-html/index.html";

unsigned long lastTime = 0;
unsigned long timerDelay = 200;

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;

      String serverPath = serverName;


      http.begin(serverPath.c_str());


      int httpResponseCode = http.GET();

      if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      } else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }

      http.end();
    } else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}