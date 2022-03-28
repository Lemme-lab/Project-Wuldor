#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>
#include <AccelStepper.h>
#include "Main_Header.h"





void setup() {
  Serial.begin(9600);
  DDRD |= 0b11111100;
  DDRB |= 0b00000011;
  DDRC |= 0b00011111;
  //Motor motor1 = new Motor();

}

void loop() {

}