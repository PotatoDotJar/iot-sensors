#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 17
#define LIGHT_SENSOR 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


void setup() {
    Serial.begin(115200);

    pinMode(LIGHT_SENSOR, INPUT_PULLDOWN);

    sensors.begin(); 
}

void loop() {
    sensors.requestTemperatures();
    sensors.setResolution(12);
    Serial.print(millis());
    Serial.print("  Temp: ");
    Serial.print(sensors.getTempFByIndex(0) + String("F"));
    Serial.print("  Light: ");
    Serial.println(analogRead(36));
}