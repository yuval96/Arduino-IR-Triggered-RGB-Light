#include "LowPower.h"

const int R = 3;
const int G = 5;
const int B = 6;
const int IR = 2;

volatile bool isTriggered = false;
const unsigned long ON_TIME_MS = 10000;

void IR_ISR() {
  isTriggered = true;
}

void setup() {
  //LEDs output
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  pinMode(IR, INPUT_PULLUP); //IR sensor input LOW = activated
  attachInterrupt(digitalPinToInterrupt(IR), IR_ISR, FALLING);

  turnOFF();
}

void loop() {

  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

  if(isTriggered){
    isTriggered = false;
    turnON();

    unsigned long t0 = millis();
    while(millis() - t0 < ON_TIME_MS){}

    turnOFF();
  }

}


void turnON(){
  analogWrite(R,255);
  analogWrite(G,255);
  analogWrite(B,255);
}

void turnOFF(){
  analogWrite(R,0);
  analogWrite(G,0);
  analogWrite(B,0);
}