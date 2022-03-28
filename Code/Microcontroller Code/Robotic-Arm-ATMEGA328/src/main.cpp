#include <Arduino.h>
#include <avr/io.h>
#include <AccelStepper.h>
#include "Main_Header.h"
#include <SPI.h>

char buf [30];
volatile byte pos;
volatile boolean senden;
int motor_values[7];
String conv = "";
int counter = 0;

#define step1 19
#define step2 20
#define step3 22
#define step4 0
#define step5 8
#define step6 10

#define dir1 19
#define dir2 21
#define dir3 23
#define dir4 1
#define dir5 9
#define dir6 11

ISR (SPI_STC_vect)  {
byte c = SPDR;  
  
if (pos < sizeof buf){
  buf [pos++] = c;  
    }  
  }

  Motor motor1 (step1, dir1, 1);
  Motor motor2 (step2, dir2, 1);
  Motor motor3 (step3, dir3, 1);
  Motor motor4 (step4, dir4, 1);
  Motor motor5 (step5, dir5, 1);
  Motor motor6 (step6, dir6, 1);


void setup() {
  Serial.begin (9600);  
  
  SPCR |= bit (SPE);  

  pinMode(MISO, OUTPUT);
  
  pos = 0;  
  senden = false;  

  SPI.attachInterrupt();  

  DDRD |= 0b11111100;
  DDRB |= 0b00000011;
  DDRC |= 0b00011111;
}

void loop() {
  if(buf[pos] ==  'E'){
    if(buf[0] == 'R'){
      for(int i = 0; i<pos;i++){
        if(buf[i] != ','){
          conv+=buf[i];
        }else{
          motor_values[counter] =  conv.toInt();
          counter++;
        } 
      }
    }

    if(buf[0] == 'D'){
      motor1.setmoveto(motor_values[0]);
      motor2.setmoveto(motor_values[1]);
      motor3.setmoveto(motor_values[2]);
      motor4.setmoveto(motor_values[3]);
      motor5.setmoveto(motor_values[4]);
      motor6.setmoveto(motor_values[5]);
      driveMotor(motor1,motor2,motor3,motor4,motor5,motor6);
    }
  }
}