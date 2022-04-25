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


char buf[50];
volatile byte pos;
volatile boolean senden;

int motor_values[motor_length];
int arr_motor_value[motor_arr][motor_length];
String motor_values_return[motor_length];
bool drive_check = false;

int arr_counter = 0;
String conv = "";
int counter = 0;
int last_stop = 0;
bool hold = false;

int tempPin = 0;      
int printPin = 2;     
int erasePin = 4;    
int address = 0;   
bool testmode = true; 

String input_terminal;
bool test_inter = false;
 

#define step1 2
#define step2 4
#define step3 6
#define step4 8
#define step5 14
#define step6 16

#define dir1 3
#define dir2 5
#define dir3 7
#define dir4 9
#define dir5 15
#define dir6 17

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
   Serial.println("Test Features:  ");
   Serial.println("");
}

void driveMotors() {
  Serial.println("Starting first row of coordinates: ");
  do{
    if (buf[0] != 'H' && buf[0] != 'O') {
      motor1.setmoveto(arr_motor_value[last_stop][0]);
      Serial.print(arr_motor_value[last_stop][0]);
      Serial.print(", ");
      motor2.setmoveto(arr_motor_value[last_stop][1]);
      Serial.print(arr_motor_value[last_stop][1]);
      Serial.print(", ");
      motor3.setmoveto(arr_motor_value[last_stop][2]);
      Serial.print(arr_motor_value[last_stop][2]);
      Serial.print(", ");
      motor4.setmoveto(arr_motor_value[last_stop][3]);
      Serial.print(arr_motor_value[last_stop][3]);
      Serial.print(", ");
      motor5.setmoveto(arr_motor_value[last_stop][4]);
      Serial.print(arr_motor_value[last_stop][4]);
      Serial.print(", ");
      motor6.setmoveto(arr_motor_value[last_stop][5]);
      Serial.print(arr_motor_value[last_stop][5]);
      Serial.print(", ");
      driveMotor(motor1, motor2, motor3, motor4, motor5, motor6);
      Serial.println();

      motor_values_return[0] = arr_motor_value[last_stop][motor_values[0]];
      motor_values_return[1] = arr_motor_value[last_stop][motor_values[1]];
      motor_values_return[2] = arr_motor_value[last_stop][motor_values[2]];
      motor_values_return[3] = arr_motor_value[last_stop][motor_values[3]];
      motor_values_return[4] = arr_motor_value[last_stop][motor_values[4]];
      motor_values_return[5] = arr_motor_value[last_stop][motor_values[5]];



    } else if (buf[0] != 'O' || input_terminal == "Stop") {
      last_stop == arr_counter;
      Serial.println("Stopping Motors");
    } else if (buf[0] != 'H' || input_terminal == "Hold") {
      hold = true;
      Serial.println("Holding Motors");
    }

    last_stop++;

   if(hold == false ){
     drive_check = true;
   }else if( last_stop < arr_counter){
     drive_check = true;
   }
    
  }while(drive_check == false);

  drive_check = false;
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

void testingMode(){
      if(input_terminal == "Stop Test"){
			Serial.println("Ending Serial Communication");
		  testmode = false;
		}

       
    if(input_terminal == "Test") {
       Serial.println("Giving Motor Array Values!");
       arr_motor_value[0][0] = 180;
       Serial.print(arr_motor_value[0][0]);
       Serial.print(", ");
       arr_motor_value[0][1] = 90;
       Serial.print(arr_motor_value[0][1]);
       Serial.print(", ");
       arr_motor_value[0][2] = 45;
       Serial.print(arr_motor_value[0][2]);
       Serial.print(", ");
       arr_motor_value[0][3] = 30;
       Serial.print(arr_motor_value[0][3]);
       Serial.print(", ");
       arr_motor_value[0][4] = 10;
       Serial.print(arr_motor_value[0][4]);
       Serial.print(", ");
       arr_motor_value[0][5] = 340;
       Serial.print(arr_motor_value[0][5]);
       arr_counter=1;
       Serial.println("");
       Serial.println("");
    }

    if (input_terminal == "Read") {
       Serial.println("Starting to Read Input Data...");
      ReadInput();
      Serial.println("Finished Read Input Data!");
      Serial.println("");
      Serial.println("");
    }

    if (input_terminal == "Save") {
      Serial.println("Starting to Save Commands to EEPROM...");
      SaveCommands();
      Serial.println("Finished Save Commands to EEPROM!");
      Serial.println("");
      Serial.println("");
    }

    if (input_terminal == "Drive") {
       Serial.println("Starting to Drive Motors...");
      driveMotors();
      Serial.println("Finished Driving Motors!");
      Serial.println("");
      Serial.println("");
    }

    if (input_terminal == "Delete") {
      Serial.println("Deleting EEPROM...");
      clearEEPROM();
      Serial.println("Finished Deleting EEPROM!");
      Serial.println("");
      Serial.println("");
    }

  	}

void loop() {
   if(!Serial.available()){
		  testmode = true;
		}

  if(Serial.available() && testmode == true){
        input_terminal = Serial.readStringUntil('\n');
        testingMode();
    }

  if (buf[pos] == 'E') {

    if (buf[0] == 'R') {
       Serial.println("Starting to Read Input Data...");
      ReadInput();
      Serial.println("Finished Read Input Data!");
      Serial.println("");
    }

    if (buf[0] == 'S') {
      Serial.println("Starting to Save Commands to EEPROM...");
      SaveCommands();
      Serial.println("Finished Save Commands to EEPROM!");
      Serial.println("");
    }

    if (buf[0] == 'D') {
       Serial.println("Starting to Drive Motors...");
      driveMotors();
      Serial.println("Finished Driving Motors!");
      Serial.println("");
    }

    if (buf[0] == 'l') {
      Serial.println("Deleting EEPROM...");
      clearEEPROM();
      Serial.println("Finished Deleting EEPROM!");
      Serial.println("");
    }
    
  }
}



ISR(SPI_STC_vect) {
  Serial.println("Incoming input from ESP32...");
  byte c = SPDR;
  for (size_t i = 0; i < 50; i++)
  {
    buf[i] = ' ';
  }
  

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


/*
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 3
#define stepPin 2
#define motorInterfaceType 1

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  // Set the maximum speed in steps per second:
  stepper.setMaxSpeed(6000);
}

void loop() {
  // Set the speed in steps per second:
  stepper.setSpeed(400);
  // Step the motor with a constant speed as set by setSpeed():
  stepper.runSpeed();
}*/