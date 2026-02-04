#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 10); 
const byte address[6] = "BUTT8";
unsigned char receivedCommand = '0';

const int leftSpeed = 3;
const int leftIn1 = A0; // backward
const int leftIn2 = A1; // forward 

const int rightSpeed = 9;
const int rightIn1 = A2; // backward 
const int rightIn2 = A3; // forward 

const int littleButterfly = 5; // 1:30
const int bigButterfly = 6; // 1:10

int currentSpeed = 0;
const int accelerationSpeed = 5;
const int maxSpeed = 255;

const int carStartThreshold = 100;
const int minWingsSpeed = 90;

const int PWM_MIN = 0;
const int PWM_MAX = 255;

void setup() {
  Serial.begin(9600);

  pinMode(leftSpeed, OUTPUT); 
  pinMode(leftIn1, OUTPUT); 
  pinMode(leftIn2, OUTPUT);
  pinMode(rightSpeed, OUTPUT); 
  pinMode(rightIn1, OUTPUT); 
  pinMode(rightIn2, OUTPUT);

  pinMode(littleButterfly, OUTPUT);
  pinMode(bigButterfly, OUTPUT);

  analogWrite(leftSpeed, 0); 
  analogWrite(rightSpeed, 0);
  analogWrite(littleButterfly, 0);
  analogWrite(bigButterfly, 0);

  radio.begin();
  radio.setChannel(105);
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening(); 
  Serial.println("START");
}

void loop() {
  if (radio.available()) {
    radio.read(&receivedCommand, sizeof(receivedCommand));
    Serial.print("Comanda primita: ");
    Serial.print(receivedCommand);
  }
  if (receivedCommand == 1) {
    digitalWrite(leftIn1, LOW);  digitalWrite(leftIn2, HIGH);
    digitalWrite(rightIn1, LOW); digitalWrite(rightIn2, HIGH);
  } 
  else if (receivedCommand == 2) {
    digitalWrite(leftIn1, HIGH); digitalWrite(leftIn2, LOW);
    digitalWrite(rightIn1, HIGH); digitalWrite(rightIn2, LOW);
  } 
  else if (receivedCommand == 3) {
    digitalWrite(leftIn1, HIGH); digitalWrite(leftIn2, LOW);
    digitalWrite(rightIn1, LOW); digitalWrite(rightIn2, HIGH);
  } 
  else if (receivedCommand == 4) {
    digitalWrite(leftIn1, LOW); digitalWrite(leftIn2, HIGH);
    digitalWrite(rightIn1, HIGH); digitalWrite(rightIn2, LOW);
  } 
  else if (receivedCommand == 0) {
    digitalWrite(rightIn1, LOW);
    digitalWrite(rightIn2, LOW);
    digitalWrite(leftIn1, LOW);
    digitalWrite(leftIn2, LOW);
  } 
  else {
    digitalWrite(rightIn1, LOW);
    digitalWrite(rightIn2, LOW);
    digitalWrite(leftIn1, LOW);
    digitalWrite(leftIn2, LOW);
  }

  if (receivedCommand >= 1 && receivedCommand <= 4) {
    currentSpeed = currentSpeed + accelerationSpeed;
    if (currentSpeed > maxSpeed)
      currentSpeed = maxSpeed;
  }
  else {
    currentSpeed = currentSpeed - accelerationSpeed;
    if (currentSpeed < 0) currentSpeed = 0;
  }

  analogWrite(leftSpeed, currentSpeed);
  analogWrite(rightSpeed, currentSpeed);

  int wingsPwm = 0;

  if (currentSpeed > carStartThreshold) {
    wingsPwm = map(currentSpeed, PWM_MIN, PWM_MAX, minWingsSpeed, PWM_MAX);
  } 
  else {
    wingsPwm = 0;
  }

  if (receivedCommand == 2) {
    wingsPwm = 0;
  }

  analogWrite(littleButterfly, wingsPwm);
  analogWrite(bigButterfly, wingsPwm);

  delay(10);
}

