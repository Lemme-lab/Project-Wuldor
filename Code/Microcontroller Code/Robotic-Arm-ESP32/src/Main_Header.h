 #include "WiFi.h"
 #include "ESPAsyncWebServer.h"
 #include "SPIFFS.h"
 #include <Arduino.h>

void web();
void setMotor(int dir_pin, int speed_pin, int motorInterfaceType);