#include "Arduino.h"
int potPin = 35;

void setup() {
    Serial.begin(115200);
    // konfigurer til å lese verdi (INPUT) fra potmeter
    pinMode(potPin, INPUT);
}

void loop() {
    Serial.println(analogRead(potPin));
    delay(100);    
}