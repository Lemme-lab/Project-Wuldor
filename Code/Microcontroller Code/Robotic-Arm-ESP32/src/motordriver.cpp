#include <Arduino.h>
#include <AccelStepper.h>
#include "Main_Header.h"


void setMotor(int dir_pin, int speed_pin, int motorInterfaceType, int moveto){
AccelStepper stepper = AccelStepper(motorInterfaceType, speed_pin, dir_pin);
stepper.setMaxSpeed(1000);
stepper.setAcceleration(50);
stepper.moveTo(dir_pin);
stepper.moveTo(moveto);

Serial.print("Motor go ehhhhhh");
int counter = 0;
while(stepper.distanceToGo() != 0){
  stepper.run();
  counter++;
  if(counter == 500000){
      counter = 0;
      Serial.print(".");
  }
  
 }
 Serial.println(" ");
 Serial.println("Motor go chilling");
 stepper.stop();
}
