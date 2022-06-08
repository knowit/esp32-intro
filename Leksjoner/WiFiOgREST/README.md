
# WiFi og REST- tjenester

## Oppkobling mot WiFi

ESP32 har innebygget WiFi. Den kan være en webserver, en webklient, aksesspunkt (med begrenset funksjonalitet). Den kan også benyttes til annen form for nettverkstrafikk (f.eks UDP).

Bruk samme krets som i [Styr LED fra knapp](../StyrLEDFraKnapp/README.md)

Lin inn følgende program, og sett inn korrekt nettverksnavn og passord i ```sid``` og ```password```:

```cpp
#include "Arduino.h"
#include "WiFi.h"

int ledPin = 32;
const char *ssid = "X";
const char *password = "X";

void setup()
{
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    delay(500); // vent litt til seriell kommunikasjon er opprettet
    WiFi.begin(ssid, password);

    Serial.println("Connecting to WiFi..");
    while (WiFi.status() != WL_CONNECTED)
    {
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
}

void loop() {}
```

### Kommentarer til programmet:

- ```#include "WiFi.h"``` inkluderer innebygget ESP-32 bibliotek for å håndtere WiFi
- ```WiFi.begin(ssid, password);``` - starter WiFi- funksjonaliteten i chippen
- ```while (WiFi.status() != WL_CONNECTED) ``` - venter til WiFi er koblet opp
- ```WiFi.localIP()``` - returnerer IP- adressen til chippen





## HTTP GET
Nå skal vi lage to enkle tjenester som enten skrur av eller på LED.

I denne oppgaven skal vi bruke json. For å gjøre dette enklere, inkluderer vi et eksternt bibliotek for dette. Legg til disse linjene i ```platformio.ini```:

```ini
lib_deps =
     bblanchon/ArduinoJson @ ^6.18.0
```

Lim inn dette programmet og sett SSID og passord:

```cpp
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
  server.send(200, "application/json", "{\n\"state\":\"on\"\n}");
}

void ledOff() {
  Serial.println("LED off");
  digitalWrite(ledPin, LOW);
  server.send(200, "application/json", "{\n\"state\":\"off\"\n}");
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

```

Hvis EP32-en har koblet opp til Wifi skal det vises en melding tilsvarende denne:

```
Connecting to WiFi..
......
Connected to the WiFi network. My IP: 192.168.10.162
```

Siste linje viser IP-adresse til enheten.

Du kan nå teste ut GET- kallene ved å åpne f.eks disse adressene i en nettleser:

* [http://192.168.10.162/led_on]() - for å skru på LED
* [http://192.168.10.162/led_off]() - for å skru av LED

**OBS!** Husk å bytte ut til korrekt IP!

### Kommentarer til programmet:

- ```#include <WebServer.h>"``` - inkluderer bibliotek med webtjener fra standardbiblioteket til ESP32
- ```WebServer server(80)"``` - setter opp tjeneren på port 80
- ```server.on("/led_on", ledOn)"``` - knytter stien ```/led_on``` opp mot funksjonen ```ledOn```
- ```void ledOn()"``` - implementerer funksjonalitet for å svare på stien ```/led_on```
- ```server.begin()"``` - starter serveren
- ```server.handleClient()"``` - ber serveren håndtere trafikk

## REST- tjeneste

Nå skal implemetere samme løsning som over, men på en mer elegant måte.
Vi skal lage en REST- tjeneste som lytter på POST- requester og skrur av eller på lampen.



Lim inn dette programmet:

```cpp
#include "Arduino.h"
#include "WiFi.h"
#include <WebServer.h>
#include <ArduinoJson.h>

int ledPin = 32;
const char *ssid = "X";
const char *password = "X";

// Web server running on port 80
WebServer server(80);

// JSON data buffer
StaticJsonDocument<250> jsonDocument;

void handlePost() {
    String body = server.arg("plain");
    Serial.print("BODY: ");
    Serial.println(body);
    deserializeJson(jsonDocument, body);

    // Hent verdier fra request
    int state = jsonDocument["state"];
    Serial.print("State: ");
    Serial.println(state);
    digitalWrite(ledPin, state);

    // Respond to the client
    server.send(200, "application/json", "{}");
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

    server.on("/led", HTTP_POST, handlePost);

    // start server
    server.begin();
}

void loop() {
    server.handleClient(); // håndterer innkomnende trafikk
}
```

Du kan nå teste endepunktet med cURL:

Husk å sette inn riktig IP- adresse i eksemplene under!

For å skru på LED:
```
curl -d '{"state":"1"}' -H "Content-Type: application/json" -X POST http://192.168.10.154:80/led
```

For å skru av LED:
```
curl -d '{"state":"0"}' -H "Content-Type: application/json" -X POST http://192.168.10.154:80/led
```

**OBS!** Husk å bytte ut til korrekt IP!

### Kommentarer til programmet:

- ```#include <ArduinoJson.h>``` - inkluderer bibliotek for JSON
- ```server.on("/led", HTTP_POST, handlePost)``` - registrerer endepunkt med POST
- ```void handlePost()``` - metode for å håndtere POST
- ```String body = server.arg("plain")``` - henter HTTP Body
- ```deserializeJson(jsonDocument, body)``` - tolker/ deserialiserer JSON
- ```int state = jsonDocument["state"]``` - henter element i JSON
- ```digitalWrite(grovePin2, state)``` - Tenner/ slukker lampen
- ```server.send(200, "application/json", "{}")``` - Returnerer 200 OK (uansett hvordan det går :) )



### Kilder
* [techtutorialsx: ESP32: Connecting to a WiFi network](https://techtutorialsx.com/2017/04/24/esp32-connecting-to-a-wifi-network/)
* [ESP32 Rest API: How to implement an ESP32 API server using PlatformIO](https://www.survivingwithandroid.com/esp32-rest-api-esp32-api-server/)
