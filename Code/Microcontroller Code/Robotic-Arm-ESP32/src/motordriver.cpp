#include <Arduino.h>
#include <AccelStepper.h>
#include "Main_Header.h"


void setMotor(int dir_pin, int speed_pin, int motorInterfaceType){
AccelStepper stepper = AccelStepper(motorInterfaceType, speed_pin, dir_pin);
stepper.setMaxSpeed(1000);
stepper.setSpeed(400);
stepper.runSpeed();
delay(100);
stepper.stop();
}
