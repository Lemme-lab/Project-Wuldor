#include <NeoPixelBus.h>
#include "header.h"

const uint16_t PixelCount = 6; 
const uint8_t PixelPin = 9;  

#define colorSaturation 128

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

HslColor hslRed(red);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslWhite(white);
HslColor hslBlack(black);



void LedRing(int type, int speed)
{
    strip.Begin();
    strip.Show();


    Serial.println();
    Serial.println("Running Strip...");

if(type == 1){
 for(int i = 0; i<PixelCount; i++){
      strip.SetPixelColor(i, green);
      strip.SetPixelColor(i-1, black);
      strip.Show();
      delay(speed);
    }

    for(int i = 0; i<PixelCount; i++){
      strip.SetPixelColor(i, white);
      strip.Show();
    }
    
}else if(type == 2){
 for(int i = 0; i<PixelCount; i++){
      strip.SetPixelColor(i, red);
      strip.Show();
    }
}

    
}