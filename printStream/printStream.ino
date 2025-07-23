#include "config.hpp"
#include "ui.hpp"

const byte type_of_FirstRun = MoveForward;
bool Rotate = true;



void initPins();
void drive(int left, int right);

void searchingEnemy(){
  drive(searchingSpeed,searchingSpeed);
  if(digitalReadSensors() >=1 ){
    return;
  }
}

byte digitalReadSensors() {
  byte digitalSensors = 0;
  if (digitalRead(VS_SenLeftMain) == 1) {
    digitalSensors += 4;
  }
  if (digitalRead(VS_SenCentreMain) == 1) {
    digitalSensors += 2;
  }
  if (digitalRead(VS_SenRightMain) ==1) {
    digitalSensors += 1;
  }
  return(digitalSensors);
}

void FirstMoveRun() {
  if (type_of_FirstRun == MoveForward) {
    if (Rotate == true) {
      drive(50, -50);
      delay(300);
    }
    drive(speedOfFirstRun, speedOfFirstRun);
    delay(timeOfFirstRun);
  }
  if (type_of_FirstRun == MoveLeft) {
    if (Rotate == true) {
      drive(50, -50);
      delay(300);
    }
    drive(speedOfFirstRun + 20, speedOfFirstRun);
    delay(timeOfFirstRun);
  }
  if (type_of_FirstRun == MoveRight) {
    if (Rotate == true) {
      drive(50, -50);
      delay(300);
    }
    drive(speedOfFirstRun, speedOfFirstRun + 20);
    delay(timeOfFirstRun);
  }
  if (type_of_FirstRun == MoveRandom) {
    if (Rotate == true) {
      drive(50, -50);
      delay(300);
    }
    byte moveRandom = random(1, 4) - 1;
    if (moveRandom == MoveForward) {
      drive(speedOfFirstRun, speedOfFirstRun);
      delay(timeOfFirstRun);
    }
    if (moveRandom == MoveLeft) {
      drive(speedOfFirstRun + 20, speedOfFirstRun);
      delay(timeOfFirstRun);
    }
    if (moveRandom == MoveRight) {
      drive(speedOfFirstRun, speedOfFirstRun + 20);
      delay(timeOfFirstRun);
    }
  }
}

void SumoRun() {
  FirstMoveRun();
  if(digitalReadSensors() == 0){
    searchingEnemy();
  }

}

void Sensors() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 10);
  display.println(F("Sensors..."));
  delay(100);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  while (!digitalRead(Button_next)) {
    display.setCursor(5, 10);
    display.println(F(digitalRead(VS_SenLeftMain)));
    display.setCursor(30, 10);
    display.println(F(digitalRead(VS_SenCentreMain)));
    display.setCursor(55, 10);
    display.println(F(digitalRead(VS_SenRightMain)));
    display.setCursor(10, 30);
    display.println(F(analogRead(Line_sensor_Left)));
    display.setCursor(40, 30);
    display.println(F(analogRead(Line_sensor_Right)));
    delay(50);
  }
}

void info() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 10);
  display.println(F(minSpeed));
  display.setCursor(30, 10);
  display.println(F(maxSpeed));
}

void testLine() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 10);
  display.println(F("TestLine..."));
  delay(100);
  while (!digitalRead(Button_next)) {
    display.clearDisplay();
    //display.setTextSize(2);
    //display.setTextColor(SSD1306_WHITE);
    display.setCursor(20, 15);
    display.println(F(analogRead(Line_sensor_Left)));
    display.setCursor(80, 15);
    display.println(F(analogRead(Line_sensor_Right)));
    delay(50);
  }
}

void testDrive() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(5, 10);
  display.println(F("TestDrive..."));
  delay(100);
  while (!digitalRead(Button_next)) {
    drive(100, 100);
  }
  delay(300);
}

void initPins() {
  pinMode(LED1, OUTPUT);
  pinMode(Button_next, INPUT_PULLUP);
  pinMode(LED2, OUTPUT);
  pinMode(Button_enter, INPUT_PULLUP);
  pinMode(Start_stop1, OUTPUT);
  pinMode(VS_Sen4, INPUT);
  pinMode(OLEDSDA, OUTPUT);
  pinMode(OLEDSCL, OUTPUT);
  pinMode(VS_SenLeftMain, INPUT);
  pinMode(VS_SenCentreMain, INPUT);
  pinMode(VS_SenRightMain, INPUT);
  pinMode(R_motor1, OUTPUT);
  pinMode(R_motor2, OUTPUT);
  pinMode(L_motor1, OUTPUT);
  pinMode(L_motor2, OUTPUT);
  pinMode(Start_stop2, OUTPUT);
}

void drive(int left, int right) {
  left = constrain(left, minSpeed, maxSpeed);
  right =constrain(right, minSpeed, maxSpeed);
  if (left > 0) {
    digitalWrite(L_motor1, 1);
    analogWrite(L_motor2, 255 - left);
  } else {
    digitalWrite(L_motor2, 1);
    analogWrite(L_motor1, 255 + left);
  }
  if (right > 0) {
    digitalWrite(R_motor1, 1);
    analogWrite(R_motor2, 255 - right);
  } else {
    digitalWrite(R_motor2, 1);
    analogWrite(R_motor1, 255 + right);
  }
}

void setup() {
  Serial.begin(9600);
  initPins();
  initOLED();
  showLogo();
}

void loop() {
  byte cmd = navigateMenu();
  switch (cmd) {
    case cmdRun:
      break;

    case cmdTestDrive:
      testDrive();
      break;

    case cmdSensors:
      Sensors();
      break;

    case cmdTestLine:
      testLine();
      break;

    case cmdInfo:
      info();
      break;

    case cmdSettings:
      break;
  }
}
