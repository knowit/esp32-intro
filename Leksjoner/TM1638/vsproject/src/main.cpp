#include <TM1638plus.h>

#define STROBE_TM 33
#define CLOCK_TM 32
#define DIO_TM 25
bool high_freq = true; //default false, If using a high freq CPU > ~100 MHZ set to true.

TM1638plus tm(STROBE_TM, CLOCK_TM, DIO_TM, high_freq);
int counter = 0;

void clearLEDS() {
    for (int i = 0; i <= 7; i++) {
        tm.setLED(i, 0);
    }
}

void setup() {
    Serial.begin(115200);
    tm.displayBegin();
    Serial.println("OK");
    tm.displayText("Knowit");
}

void loop() {

    uint8_t buttons = tm.readButtons();

    if (bitRead(buttons, 1)) {
        clearLEDS();
        tm.setLED(1, 1);
        tm.displayText("HWGuild  ");
    }

    if (bitRead(buttons, 2)) {
        clearLEDS();
        tm.setLED(2, 1);
        tm.displayText("knwowit  ");
    }

    if (bitRead(buttons, 3)) {
        clearLEDS();
        tm.setLED(3, 1);
        tm.displayIntNum(counter++);
    }

    if (bitRead(buttons, 4)) {
        clearLEDS();
        tm.setLED(4, 1);
        counter = 0;
        tm.displayIntNum(counter);
    }

}
