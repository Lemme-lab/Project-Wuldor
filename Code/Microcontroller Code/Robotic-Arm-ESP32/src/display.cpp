#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_I2CDevice.h>
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>             // Arduino SPI library

#define TFT_MOSI 23  // SDA Pin on ESP32
#define TFT_SCLK 18  // SCL Pin on ESP32
#define TFT_CS   5  // Chip select control pin
#define TFT_DC    21  // Data Command control pin
#define TFT_RST   4  // Reset pin (could connect to RST pin)


// Initialize Adafruit ST7789 TFT library
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void display_contents(const unsigned char contents[] PROGMEM){   

  tft.init(135, 240, SPI_MODE2);    // Init ST7789 display 135x240 pixel
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);
 
  tft.invertDisplay(true);
  
  tft.drawBitmap(0,0,contents,240,135, ST77XX_WHITE);

}