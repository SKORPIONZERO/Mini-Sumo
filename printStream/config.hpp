#pragma once

const byte LED1 = 0;
const byte Button_next = 1;
const byte LED2 = 2;
const byte Button_enter = 3;
const byte Start_stop1 = 4; //start = 1, when start is pressed
const byte VS_Sen5 = 5;
const byte OLEDSDA = 6;
const byte OLEDSCL = 7;
const byte VS_SenLeftMain = 8;
const byte VS_Sen4 = 9;
const byte VS_SenCentreMain = 10;
const byte L_motor1 = 11;
const byte L_motor2 = 12;
const byte R_motor1 = 13;
const byte R_motor2 = 14;
const byte Start_stop2 = 15; //start = 0, when stop is pressed
const byte VS_SenRightMain = 16;
const byte V_Metr = 17;
const byte Line_sensor_Left = 18;
const byte Line_sensor_Right = 19;

const int minSpeed = -120;
const int maxSpeed = 255;
const int speedOfFirstRun = 150;
const int timeOfFirstRun = 300;
const int searchingSpeed = 60;

enum FirstMoveRun {MoveForward, MoveLeft, MoveRight, MoveRandom};