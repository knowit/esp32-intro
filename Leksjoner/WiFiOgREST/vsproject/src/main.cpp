#include "Arduino.h"
#include "WiFi.h"
#include <WebServer.h>
#include <ArduinoJson.h>

int ledPin = 32;
const char *ssid = "X";
const char *password = "X";

// Web server running on port 80
WebServer server(80);

void ledOn() {
  Serial.println("LED on");
  digitalWrite(ledPin, HIGH);
  server.send(200, "application/json", "{state:\"on\"}");
}

void ledOff() {
  Serial.println("LED off");
  digitalWrite(ledPin, LOW);
  server.send(200, "application/json", "{state:\"off\"}");
}

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    delay(500); // vent litt til seriell kommunikasjon er opprettet
    WiFi.begin(ssid, password);

    Serial.println("Connecting to WiFi..");
    while (WiFi.status() != WL_CONNECTED) {
        digitalWrite(ledPin, HIGH);
        delay(250);
        digitalWrite(ledPin, LOW);
        delay(250);
        Serial.print(".");
    }
    Serial.println("");

    digitalWrite(ledPin, HIGH);

    Serial.print("Connected to the WiFi network. My IP: ");
    Serial.println(WiFi.localIP());

    server.on("/led_on", ledOn);
    server.on("/led_off", ledOff);

    // start server
    server.begin();
}

void loop() {
    server.handleClient(); // håndterer innkomne trafikk
}