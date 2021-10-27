#include <Arduino.h>
#include <Servo.h>

Servo myservo;

int pos = 0;

void setup() {
    myservo.attach(32); // attaches the servo on pin 9 to the servo object
}

void loop() {
    for (pos = 0; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
    }
    delay(250);
    myservo.write(0);
    delay(1000);
}