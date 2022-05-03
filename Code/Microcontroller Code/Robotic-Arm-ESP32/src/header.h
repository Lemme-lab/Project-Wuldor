#ifndef header_h
#define header_h
#include <Arduino.h>

int web = 0;
int display = 0;

void display_contents(const unsigned char contents[] PROGMEM);
void startWebserver();
void LedRing(int type, int speed);

#endif