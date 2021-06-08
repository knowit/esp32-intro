#include "Arduino.h"
int grovePin1 = 4; // Yellow
int grovePin2 = 13; // White

// denne variabelen holder på status på knappen
bool buttonState = LOW;

void setup()  {
  // konfigurer til å lese verdi (INPUT) fra knapp
  pinMode(grovePin1, INPUT);
  // konfigurer til å gi signaler ut til LED (OUTPUT)
  pinMode(grovePin2, OUTPUT);
}


void loop() {
  // les verdi på knapp (av eller på)
  buttonState = digitalRead(grovePin1);
  // skriv verdi for å tenne eller slukke lampe
  digitalWrite(grovePin2, !buttonState);
}