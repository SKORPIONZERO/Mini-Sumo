#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

extern Adafruit_SSD1306 display;
enum CMD: byte{
  cmdRun,
  cmdTestDrive,
  cmdSensors,
  cmdTestLine,
  cmdInfo,
  cmdSettings  
};

void initOLED();
void showLogo();
byte navigateMenu();
void showItemMenu(byte item);