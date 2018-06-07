void setup(){
  for (int i = 3; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  for (int i = 3; i <= 13; i++) {
    digitalWrite(i, HIGH);
    delay(100);
  }
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  for (int i = 0; i < 4; i++) {
    delay(100);
    allOn();
    delay(100);
    allOff();    
  }
}

void loop(){
  while (Serial.available() > 0) {
    int numOfLights = Serial.parseInt() + 3;
    allOff();
    for (int i = 0; i < numOfLights; i++) {
      digitalWrite(i, HIGH);
    }
  }
}

void allOff() {
  for (int i = 3; i <= 13; i++) {
      digitalWrite(i, LOW);
  }
}

void allOn() {
  for (int i = 3; i <= 13; i++) {
    digitalWrite(i, HIGH);
  }
}

