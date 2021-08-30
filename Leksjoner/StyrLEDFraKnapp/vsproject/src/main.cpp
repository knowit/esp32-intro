#include "Arduino.h"
int buttonPin = 35;
int ledPin = 32;

// denne variabelen holder på status på knappen
bool buttonState = LOW;

void setup() {
    Serial.begin(115200);
    // konfigurer til å lese verdi (INPUT) fra knapp
    pinMode(buttonPin, INPUT);
    // konfigurer til å gi signaler ut til LED (OUTPUT)
    pinMode(ledPin, OUTPUT);
    Serial.println("Setup OK");
}

void loop() {
    buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);
    digitalWrite(ledPin, LOW);
    if( buttonState ) {
        digitalWrite(ledPin, HIGH);
        delay(2000);
    }
    
}