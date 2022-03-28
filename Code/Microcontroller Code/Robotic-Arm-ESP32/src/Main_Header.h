 #include "WiFi.h"
 #include "ESPAsyncWebServer.h"
 #include "SPIFFS.h"
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
<<<<<<< HEAD

=======
    
>>>>>>> 494ede430fb6a300d29ebf43dc6e3211d30eda97
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

void driveMotorSetup(Motor, Motor , Motor , Motor , Motor, Motor );
void driveMotor(Motor, Motor , Motor , Motor , Motor, Motor );

