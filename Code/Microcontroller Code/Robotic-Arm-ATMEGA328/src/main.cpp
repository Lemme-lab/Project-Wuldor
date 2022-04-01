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

// O -- STOP
// H -- HOLD
// S -- SAVE
// R -- Read
// D -- Drive
// E -- END
// c -- ATMEGA Check
// A -- response coordinates 


char buf[30];
volatile byte pos;
volatile boolean senden;
int motor_values[motor_length];
int arr_motor_value[20][motor_length];
int arr_counter = 0;
String conv = "";
int counter = 0;
int last_stop = 0;
bool hold = false;
String motor_values_return[motor_length];

#define step1 19
# define step2 20
# define step3 22
# define step4 0
# define step5 8
# define step6 10

# define dir1 19
# define dir2 21
# define dir3 23
# define dir4 1
# define dir5 9
# define dir6 11

Motor motor1(step1, dir1, 1);
Motor motor2(step2, dir2, 1);
Motor motor3(step3, dir3, 1);
Motor motor4(step4, dir4, 1);
Motor motor5(step5, dir5, 1);
Motor motor6(step6, dir6, 1);


void setup() {
  Serial.begin(9600);

  SPCR |= bit(SPE);

  pinMode(MISO, OUTPUT);

  pos = 0;
  senden = false;

  SPI.attachInterrupt();

  DDRD |= 0b11111100;
  DDRB |= 0b00000011;
  DDRC |= 0b00011111;
}

void driveMotors() {

  do{
    if (buf[0] != 'H' && buf[0] != 'O') {
      motor1.setmoveto(arr_motor_value[last_stop][motor_values[0]]);
      motor2.setmoveto(arr_motor_value[last_stop][motor_values[1]]);
      motor3.setmoveto(arr_motor_value[last_stop][motor_values[2]]);
      motor4.setmoveto(arr_motor_value[last_stop][motor_values[3]]);
      motor5.setmoveto(arr_motor_value[last_stop][motor_values[4]]);
      motor6.setmoveto(arr_motor_value[last_stop][motor_values[5]]);
      driveMotor(motor1, motor2, motor3, motor4, motor5, motor6);

      motor_values_return[0] = arr_motor_value[last_stop][motor_values[0]] + "";
      motor_values_return[1] = arr_motor_value[last_stop][motor_values[1]]+ "";
      motor_values_return[2] = arr_motor_value[last_stop][motor_values[2]]+ "";
      motor_values_return[3] = arr_motor_value[last_stop][motor_values[3]]+ "";
      motor_values_return[4] = arr_motor_value[last_stop][motor_values[4]]+ "";
      motor_values_return[5] = arr_motor_value[last_stop][motor_values[5]]+ "";

      last_stop++;

    } else if (buf[0] != 'O') {
      last_stop == arr_counter;
    } else if (buf[0] != 'H') {
      hold = true;
    }
    last_stop++;

  }while(last_stop < arr_counter || hold == false);

  last_stop = 0;
}



void ReadInput() {
  if (arr_counter == 19) {
    arr_counter = 0;
  }
  for (int i = 0; i < pos; i++) {
    if (buf[i] != ',') {
      conv += buf[i];
    } else {
      motor_values[counter] = conv.toInt();      
      arr_motor_value[arr_counter][counter] =  conv.toInt();  
      counter++;
    }
  }

  arr_counter++;
}



void SaveCommands() {
  /*
  for (size_t i = 0; i < arr_counter; i++) {
    EEPROM.write(eepromIndex, arr_motor_value[i]);
    eepromIndex++;
    if (eepromIndex > EEPROM_BUFFER + BUFFER_LENGTH) eepromIndex = EEPROM_BUFFER;
    Serial.println(eepromIndex);
    EEPROM.write(eepromIndex, 0xFF);
  }*/
}



void loop() {
  if (buf[pos] == 'E') {

    if (buf[0] == 'O') {
      hold = false;
      driveMotors();
    }

    if (buf[0] == 'R') {
      ReadInput();
    }

    if (buf[0] == 'S') {
      SaveCommands();
    }

    if (buf[0] == 'D') {
      driveMotors();
    }
  }
}

ISR(SPI_STC_vect) {
  byte c = SPDR;

  if (pos < sizeof buf) {
    buf[pos++] = c;
  }

  if (buf[0] == 'C') {
    SPI.transfer(true);
  }

  if (buf[0] == 'A') {
    for (int i = 0; i < motor_length; i++) {
      for (int j = 0; j < sizeof(motor_values_return[i]); j++) {
        SPI.transfer(motor_values_return[i].charAt(j));
      }
    }

  }
}