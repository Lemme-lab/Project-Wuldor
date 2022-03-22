#include <Arduino.h>
#include <AccelStepper.h>
#include "Robotic_Arm_Webserver.h"

#define dir_pin 32
#define speed_pin 33
#define motorInterfaceType 1

AccelStepper stepper = AccelStepper(motorInterfaceType, speed_pin, dir_pin);

void setup() {
  web();
  stepper.setMaxSpeed(1000);
}

void loop() {
  stepper.setSpeed(400);
  stepper.runSpeed();
  stepper.stop();

}