#include "Arduino.h"
#include "WiFi.h"
#include <WebServer.h>
#include <ArduinoJson.h>

int grovePin2 = 13; // White
const char *ssid = "X";
const char *password = "X";

// Web server running on port 80
WebServer server(80);

// JSON data buffer
StaticJsonDocument<250> jsonDocument;

void handlePost()
{
    String body = server.arg("plain");
    Serial.print("BODY: ");
    Serial.println(body);
    deserializeJson(jsonDocument, body);

    // Get RGB components
    int state = jsonDocument["state"];
    Serial.print("State: ");
    Serial.println(state);
    digitalWrite(grovePin2, state);

    // Respond to the client
    server.send(200, "application/json", "{}");
}

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

    server.on("/led", HTTP_POST, handlePost);

    // start server
    server.begin();
}

void loop()
{
    server.handleClient(); // håndterer innkomne trafikk
}