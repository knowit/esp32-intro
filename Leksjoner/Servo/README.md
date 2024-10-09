
## Servo


### Funksjonalitet

I denne leksjonen skal vi koble en servomotor til mikrokontrolleren.

### Du trenger

| Type          | Antall           | Kommentar  |  Utseende  |
| ------------- | :------------- |:-----| :----: |
| Servo | 1 | | ![](../../img/servo.png)
| Breadboard (prototypebrett)	| 1 | | ![](../../img/bb.png)
| ESP32 | 1 | | ![](../../img/esp32-devkit.jpeg)


### Konstruksjon

Sett armen på servoen slik:
![](./img/servo_uten_arm.png)
![](./img/servo_med_arm.png)


Koble kretsen slik:
![](./img/diagram.jpeg)
![](./img/bb1.png)
![](img/bb_side.png)



### TM1638 Driver

For å kommunisere med TM1638-chippen trenger vi en driver. Driveren legges inn i platform.io som en ekstern avhengighet: `roboticsbrno/ServoESP32 @ ^1.0.3`

Full `platformio.ini` fil:
```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
lib_deps =
     roboticsbrno/ServoESP32 @ ^1.0.3
```

### Program

Legg inn følgende program:

```cpp
#include <Arduino.h>
#include <Servo.h>

Servo myservo;

int pos = 0;

void setup() {
    myservo.attach(32); // attaches the servo on pin 9 to the servo object
}

void loop() {
    for (pos = 0; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
    }
    delay(250);
    myservo.write(0);
    delay(1000);
}

```

Når du kjører koden, styrer mikrokontrolleren servomotoren slik at den går sakte i en retning frem til 180 grader og deretter raskt tilbake til 0 grader.
