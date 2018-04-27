#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "secrets.h"

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.begin("very", WIFI_PASS);
}

void loop() {
    // higher the value, the more dry
    // lower the value, the more wet
    int water_reading = analogRead(A0);
    Serial.println(water_reading);
}
