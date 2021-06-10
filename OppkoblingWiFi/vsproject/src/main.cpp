#include "Arduino.h"
#include "WiFi.h"

int grovePin2 = 13; // White
const char *ssid = "X";
const char *password = "X";

void setup()
{
    Serial.begin(115200);
    pinMode(grovePin2, OUTPUT);
    delay(500); // vent litt til seriell kommunikasjon er opprettet
    WiFi.begin(ssid, password);

    Serial.println("Connecting to WiFi..");
    while (WiFi.status() != WL_CONNECTED)
    {
        digitalWrite(grovePin2, HIGH);
        delay(250);
        digitalWrite(grovePin2, LOW);
        delay(250);
        Serial.print(".");
    }
    Serial.println("");

    digitalWrite(grovePin2, HIGH);

    Serial.print("Connected to the WiFi network. My IP: ");
    Serial.println(WiFi.localIP());
}

void loop() {}