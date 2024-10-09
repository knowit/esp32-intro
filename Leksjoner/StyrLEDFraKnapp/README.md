## Styr LED fra knapp

### Funksjonalitet

* Når knappen trykkes skal:
	* lampen (LED) ***tennes***
* Når knappen ***IKKE*** trykkes:
	* lampen (LED) ***slukkes***

### Du trenger


| Type          | Antall           | Kommentar  |  Utseende  |
| ------------- | :------------- |:-----| :----: |
| LED           | 1    | Lampe. Farge og størrelse kan variere | ![LED](../../img/led.png)
| Trykkbryter	| 1	   |   |  ![Switch](../../img/button.png)
| ESP32         | 1 | | ![](../../img/esp32-devkit.jpeg)
| Motstand 330Ω | 1 | Denne beskytter LED mot for høy strøm | ![](../../img/330ohm.png) 	
| Motstand 10kΩ (kΩ = kiloOhm, 10kΩ = 10000 ohm) | 1  | Dette er en såkalt pull- down resistor. Mer info lenger ned på siden | ![](../../img/10kohm.png)

### Konstruksjon

![](./ressurser/styr_led_fra_knapp_bb.png)

Her er kretsen fra tre vinkler:

![](./ressurser/styr_led_fra_knapp_bb_bilde_1.png)
![](./ressurser/styr_led_fra_knapp_bb_bilde_2.png)
![](./ressurser/styr_led_fra_knapp_bb_bilde_3.png)



Motstanden på 10kΩ er koblet mellom bryter og jord, og er en såkalt pull- down motstand. Denne brukes for å "trekke" signalet ned til jord (0V). 


For mer informasjon om pull- up og pull- down, se

* [http://www.arduino.cc/en/Tutorial/DigitalPin](http://www.arduino.cc/en/Tutorial/DigitalPins)

### Program

Lim inn følgende program:

```cpp
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
    digitalWrite(ledPin, buttonState);
}
```

Last opp programmet.

Hvis du er usikker på hvordan du lager og laster opp programmer, se [Installasjon](../InstallasjonPlatformio/README.md) 

Programmet skal nå bli lastet opp. Når opplastingen er ferdig, trykker du på knappen. Lampen (LED) skal da lyse.

Lyser ikke lampen? Sjekk ut [Feilsøking:LED](../../Feilsoeking/LEDPoler/README.md)

Funker det ikke? Sjekk at LED er koblet riktig. Husk at lang fot skal kobles mot + (5V) gjennom motstanden og kort fot skal kobles mot minus/ jord (0V) .

Programmer for Arduino- plattformen har minst to funksjoner:

* ```setup``` som brukes for å konfigurasjon (initalisering av variabler, innganger m.m.). Denne funksjonen kalles **en gang** når programmet startes.
* ```loop``` kalles for evig.

Programmet fungerer slik:

 - funksjonen ```setup``` setter en pin som utgang og en pin som inngang
 - I funksjonen ```loop```:
	 - tilstanden på inngang leses av og lagres i ```buttonState```
	 - tilstand på utgang settes lik verdien av inngang

Hvis du vil at lampen skal lyse når knappen ikke er trykket inn, og ikke lyse når knappen er trykket inn, så kan du endre siste linje i loop slik:

```cpp
digitalWrite(ledPin, !buttonState);
```


### Oppgave

Endre programmet til å gjøre følgende:

* Når knappen trykkes inn: Lampen tennes
* Etter 2 sekunder: Lampen slukkes

***Tips!*** Funksjonen ```delay(ms)``` brukes for å får arduinoen til å vente. For mer info, se:

* [https://www.arduino.cc/reference/en/language/functions/time/delay/](https://www.arduino.cc/reference/en/language/functions/time/delay/)


Problemer? Se [fasit](./fasit.md)



