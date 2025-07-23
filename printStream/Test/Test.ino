const byte L_motor1 = 11;
const byte L_motor2 = 12;
const byte R_motor1 = 13;
const byte R_motor2 = 14;
const byte LED1 = 0;
const byte Button_next = 1;
const byte LED2 = 2;
const byte Button_enter = 3;
const int minSpeed = -120;
const int maxSpeed = 255;

void initPins() {
  pinMode(LED1, OUTPUT);
  pinMode(Button_next, INPUT_PULLUP);
  pinMode(LED2, OUTPUT);
  pinMode(Button_enter, INPUT_PULLUP);
  pinMode(R_motor1, OUTPUT);
  pinMode(R_motor2, OUTPUT);
  pinMode(L_motor1, OUTPUT);
  pinMode(L_motor2, OUTPUT);
}

void drive(int left, int right) {
  if (left > maxSpeed) {
    left = maxSpeed;
  }
  if (right > maxSpeed) {
    right = maxSpeed;
  }
  if (left < minSpeed) {
    left = minSpeed;
  }
  if (right < minSpeed) {
    right = minSpeed;
  }
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
}

void loop() {
  int a = analogRead(A2);
  Serial.println(a);
  delay(100);
}
