#include <Arduino.h>
#include <AccelStepper.h>
#include "Main_Header.h"

#define dir_pin 32
#define speed_pin 33
#define motorInterfaceType 1



void setup() {
  Serial.begin(9600);
  web();
  setMotor(dir_pin,speed_pin,motorInterfaceType, 200);
}

void loop() {

}