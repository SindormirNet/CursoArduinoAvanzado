#include "LowPower.h"

#define LED 11

void setup() {
    pinMode(LED, OUTPUT);
}

void loop() {
    LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);  

    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
}
