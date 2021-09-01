


### Styr LED med PWM
Vi skal nå lysintensiteten på en LED. 

Vi styrer intensiteten til lampen ved ved å å slå den fort av og på i høyt temp.  Dette kalles PWM eller pulse width modulation. 

Det man gjør er at man justerer forholdet mellom hvor ofte LEDen er på, og når den er av.

Bruk funksjonen ```analogWrite``` for å styre LED-en ved hjelp av PWM. Verdien 255 er full styrke, og verdien 0 er lavest styrke. Mer info:

* [https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)

Det du skal gjøre i denne oppgaven er å lage et program som gjør dette:

1. Les potmeterets verdi (du får det som en int mellom 0 og 1023.
2. Dimme LEDen tilsvarende verdien på potmeteret.

Oppkobling:

![](./pot_pwm_bb.png)

Problemer? Se [fasit](./fasit.md))
