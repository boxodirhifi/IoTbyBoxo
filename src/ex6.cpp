#include "Arduino.h"
#define BLUE_PIN 14

void setup() {
    Serial.begin(115200);
    pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
    if (Serial.available() > 0) {
        char c = Serial.read();
        if (c == 'B') {
            digitalWrite(BLUE_PIN, HIGH);
            Serial.println("BLUE=1");
        } else if (c == 'b') {
            digitalWrite(BLUE_PIN, LOW);
            Serial.println("BLUE=0");
        }
    }
}