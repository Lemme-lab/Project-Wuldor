#include <Arduino.h>
#include <avr/io.h>
#include <AccelStepper.h>
#include "Main_Header.h"
#include <SPI.h>
#include <EEPROM.h>


#define STATE_LOCATION 513
#define EEPROM_BUFFER 514
#define BUFFER_LENGTH 121
#define motor_length 7
#define motor_arr 20

// O -- STOP
// H -- HOLD
// S -- SAVE
// R -- Read
// D -- Drive
// E -- END
// c -- ATMEGA Check
// A -- response coordinates 
// l -- löschen vom eeprom (test feature)
// f -- speed check


char buf[30];
volatile byte pos;
volatile boolean senden;

int motor_values[motor_length];
int arr_motor_value[motor_arr][motor_length];
String motor_values_return[motor_length];

int arr_counter = 0;
String conv = "";
int counter = 0;
int last_stop = 0;
bool hold = false;

int tempPin = 0;      
int printPin = 2;     
int erasePin = 4;    
int address = 0;     
 

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

Motor motor1(step1, dir1, 1);
Motor motor2(step2, dir2, 1);
Motor motor3(step3, dir3, 1);
Motor motor4(step4, dir4, 1);
Motor motor5(step5, dir5, 1);
Motor motor6(step6, dir6, 1);


void setup() {
  Serial.begin(9600);
  Serial.println("Starting setup(): ");

  SPCR |= bit(SPE);

  pinMode(MISO, OUTPUT);

  pos = 0;
  senden = false;

  SPI.attachInterrupt();

  DDRD |= 0b11111100;
  DDRB |= 0b00000011;
  DDRC |= 0b00011111;
   Serial.println("Starting loop(): ");
}

void driveMotors() {
  do{
    if (buf[0] != 'H' && buf[0] != 'O') {
      Serial.println("Starting first row of coordinates: ");
      motor1.setmoveto(arr_motor_value[last_stop][motor_values[0]]);
      Serial.print(arr_motor_value[last_stop][motor_values[0]] + ", ");
      motor2.setmoveto(arr_motor_value[last_stop][motor_values[1]]);
      Serial.print(arr_motor_value[last_stop][motor_values[1]] + ", ");
      motor3.setmoveto(arr_motor_value[last_stop][motor_values[2]]);
      Serial.print(arr_motor_value[last_stop][motor_values[2]] + ", ");
      motor4.setmoveto(arr_motor_value[last_stop][motor_values[3]]);
      Serial.print(arr_motor_value[last_stop][motor_values[3]] + ", ");
      motor5.setmoveto(arr_motor_value[last_stop][motor_values[4]]);
      Serial.print(arr_motor_value[last_stop][motor_values[4]] + ", ");
      motor6.setmoveto(arr_motor_value[last_stop][motor_values[5]]);
      Serial.print(arr_motor_value[last_stop][motor_values[5]] + ", ");
      driveMotor(motor1, motor2, motor3, motor4, motor5, motor6);
      Serial.println();

      motor_values_return[0] = arr_motor_value[last_stop][motor_values[0]] + "";
      motor_values_return[1] = arr_motor_value[last_stop][motor_values[1]]+ "";
      motor_values_return[2] = arr_motor_value[last_stop][motor_values[2]]+ "";
      motor_values_return[3] = arr_motor_value[last_stop][motor_values[3]]+ "";
      motor_values_return[4] = arr_motor_value[last_stop][motor_values[4]]+ "";
      motor_values_return[5] = arr_motor_value[last_stop][motor_values[5]]+ "";

      last_stop++;

    } else if (buf[0] != 'O') {
      last_stop == arr_counter;
      Serial.println("Stopping Motors");
    } else if (buf[0] != 'H') {
      hold = true;
      Serial.println("Holding Motors");
    }
    last_stop++;
  }while(last_stop < arr_counter || hold == false);
  last_stop = 0;
}

void ReadInput() {
  if (arr_counter == motor_arr-1) {
    arr_counter = 0;
  }
  for (int i = 0; i < pos; i++) {
    if (buf[i] != ',') {
      conv += buf[i];
      Serial.println("Reading Input Char: " + conv);
    } else {
      motor_values[counter] = conv.toInt();      
      arr_motor_value[arr_counter][counter] =  conv.toInt();  
      Serial.println("Input Char to int: " + conv.toInt());
      counter++;
    }
  }

  arr_counter++;
}

void SaveCommands() {
  for(int i = 0; i < motor_arr; i++){
    for(int j = 0; j < motor_length; j++){
      EEPROM.write(address, arr_motor_value[i][motor_values[j]]);         
      Serial.print("Motor value stored at address ");
      Serial.println(address);
      address++;   

      if(address == EEPROM.length()) 
      {
       address = 0;              
      } 
    }
  } 
}

void clearEEPROM()
{
  for (int i = 0 ; i < EEPROM.length() ; i++) {
    if(EEPROM.read(i) != 0)                     
    {
      EEPROM.write(i, 0);                      
    }
  }
  Serial.println("EEPROM erased");
  address = 0;                                  
}



void loop() {
  if (buf[pos] == 'E') {

    if (buf[0] == 'R') {
       Serial.println("Starting to Read Input Data...");
      ReadInput();
      Serial.println("Finished Read Input Data!");
    }

    if (buf[0] == 'S') {
      Serial.println("Starting to Save Commands to EEPROM...");
      SaveCommands();
      Serial.println("Finished Save Commands to EEPROM!");
    }

    if (buf[0] == 'D') {
       Serial.println("Starting to Drive Motors...");
      driveMotors();
      Serial.println("Finished Driving Motors!");
    }

    if (buf[0] == 'l') {
      Serial.println("Deleting EEPROM...");
      clearEEPROM();
      Serial.println("Finished Deleting EEPROM!");
    }
  }
}

ISR(SPI_STC_vect) {
  Serial.println("Incoming input from ESP32...");
  byte c = SPDR;

  if (pos < sizeof buf) {
    buf[pos++] = c;
  }

  if (buf[0] == 'C') {
     Serial.println("Sending Check back...");
    SPI.transfer(true);
  }

  if (buf[0] == 'A') {
    Serial.println("Sending Motor Values back...");
    for (int i = 0; i < motor_length; i++) {
      for (int j = 0; j < sizeof(motor_values_return[i]); j++) {
        SPI.transfer(motor_values_return[i].charAt(j));
      }
    }

  }

   if (buf[0] == 'f') {
     Serial.println("Sending speed back...");
     SPI.transfer(get_speed());
  }
}