#include <TM1638plus.h>

#define STROBE_TM 33
#define CLOCK_TM 32
#define DIO_TM 25
bool high_freq = true; //default false, If using a high freq CPU > ~100 MHZ set to true.

TM1638plus tm(STROBE_TM, CLOCK_TM, DIO_TM, high_freq);

void setup()
{
    tm.displayBegin();
}

void loop()
{
    tm.displayText("HWGuild  ");
    delay(2000);
    tm.displayText("Knowit  ");
    delay(2000);
}
