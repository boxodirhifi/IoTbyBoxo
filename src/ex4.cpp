#include "Arduino.h"
#include <string.h>
#define RED_PIN 26
#define GREEN_PIN 27
#define YELLOW_PIN 12
#define BLUE_PIN 14
#define LIGHT_PIN 33

const char *lastBand = "";

void setup() {
    Serial.begin(115200);
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(YELLOW_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
    int val = analogRead(LIGHT_PIN);
    const char *band;

    // Turn all OFF first
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);

    if (val >= 0 && val <= 1023) {
        digitalWrite(BLUE_PIN, HIGH);
        band = "BLUE";
    } else if (val >= 1024 && val <= 2047) {
        digitalWrite(GREEN_PIN, HIGH);
        band = "GREEN";
    } else if (val >= 2048 && val <= 3071) {
        digitalWrite(YELLOW_PIN, HIGH);
        band = "YELLOW";
    } else {
        digitalWrite(RED_PIN, HIGH);
        band = "RED";
    }

    // Print only when the band changes
    if (strcmp(band, lastBand) != 0) {
        Serial.print("band=");
        Serial.println(band);
        lastBand = band;
    }
    delay(200);
}