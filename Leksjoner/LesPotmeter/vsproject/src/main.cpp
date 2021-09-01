#include "Arduino.h"
int potPin = 35;
int ledPin = 32;

// instillinger for PWM
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
    Serial.begin(115200);

    // konfigurer til å lese verdi (INPUT) fra potmeter
    pinMode(potPin, INPUT);
    pinMode(ledPin, OUTPUT);

    // konfigurer LED PWM
    ledcSetup(ledChannel, freq, resolution);
    // assosier PWM- kanal med led pin
    ledcAttachPin(ledPin, ledChannel);
}

void loop() {
    int potValue = analogRead(potPin);
    ledcWrite(ledChannel, potValue / 16);
}