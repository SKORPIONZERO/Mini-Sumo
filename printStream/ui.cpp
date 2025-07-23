#include <cstddef>
#include "ui.hpp"
#include "config.hpp"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire1, OLED_RESET);
const byte sizeMenu = 6;
byte activeItem = 0;

String menu[sizeMenu] = {
  "run",
  "test Drive",
  "test Sensors",
  "test Line",
  "info",
  "settings"
};

byte navigateMenu() {
  showItemMenu(activeItem);  
  while (1) {
    if(digitalRead(Start_stop1) == 1){
      return cmdRun;   
}    
    if (!digitalRead(Button_next)) {
      digitalWrite(LED1, 1);
      delay(200);
      digitalWrite(LED1, 0);
      activeItem++;
      activeItem = (activeItem + 1) % sizeMenu; 
      showItemMenu(activeItem);
    }
    if(!digitalRead(Button_enter)){
      digitalWrite(LED1, 1);
      delay(200);
      digitalWrite(LED1, 0);
      return activeItem;      
    }
  }
}

void showItemMenu(byte item) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 10);
  display.println(F("menu[item]"));
}

void initOLED() {
  Wire1.setSDA(OLEDSDA);
  Wire1.setSCL(OLEDSCL);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    //alarm
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
}

void showLogo() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 10);
  display.println(F("Printstream"));
  long timeStart = millis();
  while (millis() - timeStart < 2000) {
    if (!digitalRead(Button_enter) || !digitalRead(Button_next)) {
      return;
    }
  }
}
