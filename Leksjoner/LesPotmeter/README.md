
## Les potmeter

Et potmeter (fullt navn: på engelsk: potentiometer, på nynorsk: potensiometer) er en variabel resistor som endrer motstand når man vrir på akselen. Potmeter brukes ofte på volumkontroller og i andre applikasjoner der man ønsker å variere signalnivå. Potmeteret er en analog innenhet. Den midterste foten gir en spenning som ligger mellom de to andre avhengig av hvor posisjon på meteret.

For å lese verdier fra analoge innenheter må vi bruke en ADC (Analog Digital Converter), som er innebygget i ESP32. For å gjøre dette, bruker vi funksjonen ```analogRead```.

### Funksjonalitet

ESP32-en leser av potmeteret og rapporterer verdien tilbake til datamaskinen over serieport.

### Du trenger

| Type          | Antall           | Kommentar  |  Utseende  |
| ------------- | :------------- |:-----| :----: |
| Potmeter	| 1 | | ![LED](../../img/potmeter.png)
| Breadboard (prototypebrett)	| 1 | | ![](../../img/bb.png)
| ESP32 | 1 | | ![](../../img/esp32-devkit.jpeg)


### Konstruksjon

![](LesPotmeter_bb.png)
![](LesPotmeter_bilde_1.jpg)
![](LesPotmeter_bilde_2.jpg)

### Program

Lim inn følgende program:

```cpp
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
```

Når programmet er lastet opp og kjører, vrir du på potmeteret og ser at det leses ut ulike verdier:


```

1849
1517
999
494
35
0
0
0
0
0
0
102
459
715
831

```



