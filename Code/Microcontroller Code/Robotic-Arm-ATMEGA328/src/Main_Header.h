#ifndef Main_Header_H
#define Main_Header_H
#include <Arduino.h>


void web();
String processor(const String& var);

class Motor {       
  public:            
    int dir_pin;
    int speed_pin;
    int motorInterfaceType;
    int moveto;
    void setmoveto();

    void driveMotor();

    Motor(int dir_pin1, int speed_pin1, int motorInterfaceType1) { 
      dir_pin = dir_pin1;
      speed_pin = speed_pin1;
      motorInterfaceType = motorInterfaceType1;
    }

    void setmoveto(int input) {
      moveto = input;
    }
};

void driveMotor(Motor motor1, Motor motor2, Motor motor3, Motor motor4, Motor motor5, Motor motor6);

static int get_speed();

#endif

