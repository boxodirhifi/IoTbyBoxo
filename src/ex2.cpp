#include "Arduino.h"
#define GREEN_PIN 27
#define BUTTON_PIN 25

bool greenState = false;
bool lastButtonState = LOW; // Active HIGH button

void setup() {
    Serial.begin(115200);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
    bool currentButtonState = digitalRead(BUTTON_PIN);
    
    if (lastButtonState == LOW && currentButtonState == HIGH) {
        greenState = !greenState;
        digitalWrite(GREEN_PIN, greenState);
        Serial.print("GREEN=");
        Serial.println(greenState ? "1" : "0");
        delay(50); // debounce
    }
    lastButtonState = currentButtonState;
}