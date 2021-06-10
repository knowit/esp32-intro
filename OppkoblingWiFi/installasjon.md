

## Oppkobling mot WiFi

ESP32 har innebygget WiFi. Den kan være en webserver, en webklient, aksesspunkt (med begrenset funksjonalitet) og benyttes til annen form for nettverkstrafikk (f.eks UDP).

Bruk samme krets som i [Styr LED fra knapp](../StyrLEDFraKnapp/README.md)

Lin inn følgende program, og sett inn korrekt nettverksnavn og passord i ```sid``` og ```password```:

```
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
```




Kilder:
* [techtutorialsx: ESP32: Connecting to a WiFi network](https://techtutorialsx.com/2017/04/24/esp32-connecting-to-a-wifi-network/)
