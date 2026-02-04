#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 10); 

const byte address[6] = "BUTT8"; 

const int pinX = A0;
const int pinY = A1;
const int pinSw = 2;

const int JOYSTICK_THRESHOLD_LOW = 300;
const int JOYSTICK_THRESHOLD_HIGH = 700;

unsigned char txCommand = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinSw, INPUT_PULLUP);
  radio.begin();
  radio.setChannel(105);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW); 
  radio.stopListening();         
  radio.write(&txCommand, sizeof(txCommand));
}

void loop() {
  int x = analogRead(pinX);
  int y = analogRead(pinY);

  if (y < JOYSTICK_THRESHOLD_LOW) {
    txCommand = 1;
  }
  else if (y > JOYSTICK_THRESHOLD_HIGH) {
    txCommand = 2;
  }
  else if (x < JOYSTICK_THRESHOLD_LOW) {
    txCommand = 4;
  }
  else if (x > JOYSTICK_THRESHOLD_HIGH) {
    txCommand = 3;
  }
  else {
    txCommand = 0;
  }

  radio.write(&txCommand, 1);
  delay(150);
}