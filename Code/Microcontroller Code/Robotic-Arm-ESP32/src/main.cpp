#include <Arduino.h>
#include <AccelStepper.h>

#define dir_pin 32
#define speed_pin 33
#define motorInterfaceType 1

AccelStepper stepper = AccelStepper(motorInterfaceType, speed_pin, dir_pin);

void setup() {
  stepper.setMaxSpeed(1000);
}

void loop() {
  stepper.setSpeed(400);
  stepper.runSpeed();
}