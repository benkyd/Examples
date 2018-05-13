#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    delay(100);
    lcd.clear();
          
    while (Serial.available() > 0) {
      
      String input = String(Serial.read());

      if (input.size() > 16) {
         String subs;

         for (int i = 16; i < input.size(); i++) {
          String += input[i];
         }
        lcd.write(input);
        lcd.setCursor(0, 1);
        lcd.write(subs);        
      } else {
        lcd.write(input);        
      }
    }
  }
}
