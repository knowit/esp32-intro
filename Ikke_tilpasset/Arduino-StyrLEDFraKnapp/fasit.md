### Fasit: Styr LED fra Lampe

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
  digitalWrite(2, LOW);
  // les verdi på knapp (av eller på)
  buttonState = digitalRead(3);
  if ( buttonState) {
    digitalWrite(2, HIGH);
    delay(2000);
  }
}
```
