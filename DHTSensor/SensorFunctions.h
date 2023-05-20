#include "DHT.h"
#include <Wire.h>


#define DHTTYPE DHT11
#define DHTPin 22
DHT dht(DHTPin, DHTTYPE);

void SensorSetup() {
    delay(100);
    dht.begin();
    pinMode(DHTPin, INPUT);
}

void SensorLoop() {
    int Temperature = dht.readTemperature();
    int Humidity = dht.readHumidity();

    Serial.print(Temperature);
    Serial.print(Humidity);
}
