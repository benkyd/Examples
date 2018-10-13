#include <OneWire.h>
#include <DallasTemperature.h>

#define HIGH_PIN 12
#define ONE_WIRE_BUS 13
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

void setup() {
  pinMode(HIGH_PIN, OUTPUT);
  digitalWrite(HIGH_PIN, HIGH);
  Serial.begin(115200);
  sensors.begin();
}

void loop() { 
  sensors.requestTemperatures();
  Serial.println(sensors.getTempCByIndex(0));  
}
