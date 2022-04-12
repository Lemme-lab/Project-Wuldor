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


//this works so bad need to rework with non blocking and simultaneous code --> fixed
void driveMotor(Motor motor1, Motor motor2, Motor motor3, Motor motor4, Motor motor5, Motor motor6){

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

Serial.print("Motor go ehhhhhh: ");

int motor1_steps = (motor1.moveto) * nema17;
int motor2_steps = (motor2.moveto) * nema17_gearbox;
int motor3_steps = (motor3.moveto) * nema17_gearbox;
int motor4_steps = (motor4.moveto) * nema11_gearbox;
int motor5_steps = (motor5.moveto) * nema11_gearbox;
int motor6_steps = (motor5.moveto) * nema11;

int arr[6] = {motor1_steps,motor2_steps,motor3_steps,motor4_steps,motor5_steps,motor6_steps};
int max = 0;

for (int i = 5; i >= 0; i--)
{
  if(max < arr[i]){
    max = arr[i];
  }
}

int counter = 0;
int counter_1 = 0;

while(counter < max){

  if(counter < motor1_steps){
    stepper1.move(1);
  }

  if(counter < motor2_steps){
    stepper2.move(1);
  }

  if(counter < motor3_steps){
    stepper3.move(1);
  }

  if(counter < motor4_steps){
    stepper4.move(1);
  }

  if(counter < motor5_steps){
    stepper5.move(1);
  }

  if(counter < motor6_steps){
    stepper6.move(1);
  }


  if(counter_1 == 2000){
      Serial.print(".");
      counter_1 = 0;
  }
  
  counter++;
  counter_1++;
}

 Serial.println(" ");
 Serial.println("Motor go chilling");
}
