#include <Arduino.h>
#include <TFT_eSPI.h>
#include "header.h"
   

TFT_eSPI tft = TFT_eSPI(); 

void display_contents(uint16_t contents[] PROGMEM){  
  Serial.begin(9600);  
  Serial.print("TFT Beginn "); 
 
  tft.begin();     
  tft.setSwapBytes(true); 
 
  tft.fillScreen(TFT_BLACK);  
  tft.pushImage(0,0,135,240,contents);  
  Serial.print("TFT End"); 
}