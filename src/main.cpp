#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "secrets.h"
#include <ESP8266HTTPClient.h>

const String host = "http://7d5ccbbc.ngrok.io";
HTTPClient client;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);

    pinMode(D1, OUTPUT);
    digitalWrite(D1, LOW);

    WiFi.mode(WIFI_STA);
    WiFi.begin("very", WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    // higher the value, the more dry
    // lower the value, the more wet
    int water_reading = analogRead(A0);
    Serial.println(water_reading);

    digitalWrite(D1, HIGH);
    delay(1000);
    digitalWrite(D1, LOW);
    delay(1000);

    client.begin(host);
    int httpCode = client.POST("water_reading=" + water_reading);
    Serial.println(httpCode);
    String payload = client.getString();
    Serial.println(payload);
    Serial.println("request sent");
    client.end();
}
