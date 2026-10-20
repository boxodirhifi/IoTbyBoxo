#include "Arduino.h"
#define BUTTON_PIN 25
#define LIGHT_PIN 33
#define YELLOW_PIN 12

bool lastButtonState = LOW;

void setup() {
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT);
    pinMode(YELLOW_PIN, OUTPUT);
}

void loop() {
    bool currentButtonState = digitalRead(BUTTON_PIN);
    
    if (lastButtonState == LOW && currentButtonState == HIGH) {
        int val = analogRead(LIGHT_PIN);
        Serial.print("snapshot=");
        Serial.println(val);
        
        digitalWrite(YELLOW_PIN, HIGH);
        delay(100);
        digitalWrite(YELLOW_PIN, LOW);
        
        delay(50); // debounce
    }
    lastButtonState = currentButtonState;
}