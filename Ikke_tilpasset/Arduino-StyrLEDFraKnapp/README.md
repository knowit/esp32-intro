## Stye LED fra knapp

### Funksjonalitet

* Når knappen trykkes skal:
	* lampen (LED) ***tennes***
* Når knappen ***IKKE*** trykkes:
	* lampen (LED) ***slukkes***

### Du trenger


| Type          | Antall           | Kommentar  |  Utseeende |
| ------------- | :------------- |:-----| :----: |
| LED           | 1    | Lampe | ![LED](../img/led.png)
| Trykkbryter	| 1	   |   |  ![Switch](../img/button.png)
| Motstand 330 Ohm | 1 | Denne beskytter LED mot for høy strøm | ![](../img/330ohm.png) 	
| Motstand 10 k Ohm | 1  | Dette er en såkalt pull- down resistor. Mer info lenger ned på siden | ![](../img/10kohm.png)

### Konstruksjon

![](./oppg1.png)


Motstanden på 10 KOhm som er koblet mellom bryter og jord er en såkalt pull- down motstand, og brukes for å "trekke" signalet ned til jord ( 0 V ). 

Pass på at lampen (LED) har en lang "fot" og en kort "fot". Den lange foten skal kobles mot + (via motstand).

For mer informasjon om pull- up og pull- down, se

* [http://www.arduino.cc/en/Tutorial/DigitalPin](http://www.arduino.cc/en/Tutorial/DigitalPins)

### Program

Åpne Arduino IDE og lim inn følgende program:

```
// denne variabelen holder på status på knappen
bool buttonState = LOW;

void setup()  {
  // pin 2 konfigureres til å gi signaler ut til LED (OUTPUT)
  pinMode(2, OUTPUT);
  // pin 2 konfigureres til å lese verdi (INPUT) fra knapp
  pinMode(3, INPUT);
}


void loop() {
  // les verdi på knapp (av eller på)
  buttonState = digitalRead(3);
  // skriv verdi for å tenne eller slukke lampe
  digitalWrite(2, buttonState);
}
```

Last opp programmet med funksjonen "Upload": 

![](./upload.png)

Programmet skal nå bli lastet opp. Når opplastingen er ferdig, trykker du på knappen. Lampen (LED) skal da lyse.

Funker det ikke? Sjekk at LED er koblet riktig. Husk at lang fot skal kobles mot + (5V) gjennom motstanden og kort fot skal kobles mot minus/ jord (0V) .

Programmer for Arduino har minst to funksjoner:

* ```setup``` som brukes for å konfigurasjon (initalisering av variabler, innganger m.m.). Denne funksjonen kalles **en gang** når programmet startes.
* ```loop``` kalles for evig.

Programmet fungerer slik:

 - funksjonen ```setup``` setter pin 2 som utgang og pin 3 som inngang
 - I funksjonen ```loop```:
	 - tilstanden på inngang 3 leses av og lagres i ```buttonState```
	 - tilstand på utgang 2 settes lik verdien av utgang 3

Hvis du vil at lampen skal lyse når knappen ikke er trykket inn, og ikke lyse når knappen er trykket inn, så kan du endre siste linje i loop slik:

```
digitalWrite(2, !buttonState);
```


### Oppgave

Endre programmet til å gjøre følgende:

* Når knappen trykkes inn: Lampen tennes
* Etter 2 sekunder: Lampen slukkes

***Tips!*** Funksjonen ```delay(ms)``` brukes for å får arduinoen til å vente. For mer info, se:

* [https://www.arduino.cc/reference/en/language/functions/time/delay/](https://www.arduino.cc/reference/en/language/functions/time/delay/)


Problemer? Se [fasit](./fasit.md)



