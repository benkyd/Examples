lol#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

#define DHTPIN 13
#define DHTTYPE DHT11

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to fetch");
    lcd.clear();
    lcd.print("Failed to fetch");
    delay(500);
    return;
  }

  String temp = (String)(int)temperature;
  String humid = (String)(int)humidity;
  

  String ln1 = "Temperature : " + temp + " °C";
  String ln2 = "Humidity : " + humid + " %";

  Serial.println(ln1);
  Serial.println(ln2);
  Serial.println();

  lcd.setCursor(0,0);
  lcd.print(ln1);
  lcd.setCursor(0,1);
  lcd.print(ln2);

  delay(500);
}
