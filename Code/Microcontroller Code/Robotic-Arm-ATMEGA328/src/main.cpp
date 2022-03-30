#include <Arduino.h>
#include <avr/io.h>
#include <AccelStepper.h>
#include "Main_Header.h"
#include <SPI.h>

#define STATE_LOCATION 513 
#define EEPROM_BUFFER 514 
#define BUFFER_LENGTH 121

// O -- STOP
// H -- HOLD
// S -- SAVE
// R -- Read
// D -- Drive

char buf [30];
volatile byte pos;
volatile boolean senden;
int motor_values[7];
int arr_motor_value[20];
int arr_counter = 0;
String conv = "";
int counter = 0;
int last_stop = 0;
bool hold = false;

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

void driveMotors(){

  for (last_stop < arr_counter || hold = false;)
  {   
    if(buf[0] != 'H' && buf[0] != 'S'){
      motor1.setmoveto(arr_motor_value[motor_values[0]]);
      motor2.setmoveto(arr_motor_value[motor_values[0]]);
      motor3.setmoveto(arr_motor_value[motor_values[0]]);
      motor4.setmoveto(arr_motor_value[motor_values[0]]);
      motor5.setmoveto(arr_motor_value[motor_values[0]]);
      motor6.setmoveto(arr_motor_value[motor_values[0]]);
      driveMotor(motor1,motor2,motor3,motor4,motor5,motor6);
      last_stop++
    }   
    else if(buf[0] != 'O'){
      last_stop == arr_counter;
    }
    else if(buf[0] != 'H'){
      hold = true;
    }

  }
  last_stop = 0;
}



void ReadInput(){
  if(arr_counter == 19){
    arr_counter = 0;
  }
  for(int i = 0; i<pos;i++){
        if(buf[i] != ','){
          conv+=buf[i];
        }else{
          motor_values[counter] =  conv.toInt();
          counter++;
        } 
      }
      arr_motor_value[arr_counter] = motor_values;
      arr_counter++;
}



void SaveCommands(){
  for (size_t i = 0; i < arr_counter; i++)
  {
    EEPROM.write(eepromIndex, arr_motor_value[i]);
    eepromIndex++;
    if (eepromIndex > EEPROM_BUFFER + BUFFER_LENGTH) eepromIndex = EEPROM_BUFFER;
    Serial.println(eepromIndex);
    EEPROM.write(eepromIndex, 0xFF);
  }
  

}





void loop() {
  if(buf[pos] ==  'E'){

    if(buf[0] == 'O'){
      hold = false;
      driveMotors();
    }
    
    if(buf[0] == 'R'){
     ReadInput();
    }

    if(buf[0] == 'S'){
      SaveCommands();
    }

    if(buf[0] == 'D'){
      driveMotors();
    }
  }
}