### Fasit: Styr LED med potmeter


```
int pot = 0;
int led = 9;


void setup() {
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  analogWrite(led,analogRead(pot)/4);
}
```
