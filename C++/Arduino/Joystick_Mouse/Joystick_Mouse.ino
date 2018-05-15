#define XJOY A1
#define YJOY A0

void setup() {
 Serial.begin(9600);
}
 
void loop() {
 int joystickX = analogRead(XJOY);
 int joystickY = analogRead(YJOY);

 Serial.print("X:");
 Serial.print(((joystickX+520)/10)-103);
 Serial.print("Y:");
 Serial.print(((joystickY+520)/10)-103);
 Serial.print("  ");
 Serial.println();

 delay(50);
}
