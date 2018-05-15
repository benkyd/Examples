#define XJOY A1
#define YJOY A0

void setup() {
 Serial.begin(9600);
}
 
void loop() {
 //delay(500);
 int joystickX = analogRead(XJOY);
 int joystickY = analogRead(YJOY);
  
 Serial.print("X: ");
 Serial.print(((joystickX+520)/10)-103);
 Serial.println();
 Serial.print("Y: ");
 Serial.print(((joystickY+520)/10)-103);
 Serial.println();
}
