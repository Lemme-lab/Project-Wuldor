#include <Arduino.h>
#include <AccelStepper.h>
#include "Main_Header.h"

#define nema17 0.5555
#define nema11_gearbox 28.333
#define nema17_gearbox 55.5555
#define nema11 0.5555
#define speed_value 2000
boolean state1 = false;
boolean state2 = false;
boolean state3 = false;
boolean state4 = false;
boolean state5 = false;
boolean state6 = false;


int get_speed(){
 int speed = speed_value;
 return speed;
}


//this works so bad need to rework with non blocking and simultaneous code
void driveMotor(Motor motor1, Motor motor2, Motor motor3, Motor motor4, Motor motor5, Motor motor6){
  
int counter = 0;

AccelStepper stepper1 = AccelStepper(motor1.dir_pin, motor1.speed_pin, motor1.motorInterfaceType);
stepper1.setMaxSpeed(speed_value);
stepper1.setAcceleration(50);
AccelStepper stepper2 = AccelStepper(motor2.dir_pin, motor2.speed_pin, motor2.motorInterfaceType);
stepper2.setMaxSpeed(speed_value);
stepper2.setAcceleration(50);
AccelStepper stepper3 = AccelStepper(motor2.dir_pin, motor3.speed_pin, motor3.motorInterfaceType);
stepper3.setMaxSpeed(speed_value);
stepper3.setAcceleration(50);
AccelStepper stepper4 = AccelStepper(motor3.dir_pin, motor4.speed_pin, motor4.motorInterfaceType);
stepper4.setMaxSpeed(speed_value);
stepper4.setAcceleration(50);
AccelStepper stepper5 = AccelStepper(motor4.dir_pin, motor5.speed_pin, motor5.motorInterfaceType);
stepper5.setMaxSpeed(speed_value);
stepper5.setAcceleration(50);
AccelStepper stepper6 = AccelStepper(motor5.dir_pin, motor6.speed_pin, motor6.motorInterfaceType);
stepper6.setMaxSpeed(speed_value);
stepper6.setAcceleration(50);

Serial.print("Motor go ehhhhhh");

while(state1 == false &&  state2 == false && state3 == false && state4 == false && state5 == false && state6 == false){
stepper1.moveTo((motor1.moveto) * nema17);
stepper2.moveTo((motor2.moveto) * nema17_gearbox);
stepper3.moveTo((motor3.moveto) * nema17_gearbox);
stepper4.moveTo((motor4.moveto) * nema11_gearbox);
stepper5.moveTo((motor5.moveto) * nema11_gearbox);
stepper6.moveTo((motor5.moveto) * nema11);

if(stepper1.distanceToGo() == 0){
stepper1.stop();
state1 = true;
}
if(stepper2.distanceToGo() == 0){
stepper2.stop();
state2 = true;
}

if(stepper3.distanceToGo() == 0){
stepper3.stop();
state3 = true;
}

if(stepper4.distanceToGo() == 0){
stepper4.stop();
state4 = true;
}

if(stepper5.distanceToGo() == 0){
stepper5.stop();
state5 = true;
}

if(stepper6.distanceToGo() == 0){
stepper6.stop();
state6 = true;
}

counter++;

if(state1 == false){
stepper1.runToPosition();
}
if(state2 == false){
stepper2.runToPosition();
}
if(state3 == false){
stepper3.runToPosition();
}
if(state4 == false){
stepper4.runToPosition();
}
if(state5 == false){
stepper5.runToPosition();
}
if(state6 == false){
stepper6.runToPosition();
}

if(counter == 500000){
      counter = 0;
      Serial.print(".");
  }
}
 Serial.println(" ");
 Serial.println("Motor go chilling");
}
