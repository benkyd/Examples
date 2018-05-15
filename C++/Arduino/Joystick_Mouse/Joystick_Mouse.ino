#define XJOY A1
#define YJOY A0
#define BUTTON_JOY 4

void setup() {
 Serial.begin(9600);
 pinMode(BUTTON_JOY, INPUT_PULLUP);
}
 
void loop() {
 int joystickX = analogRead(XJOY);
 int joystickY = analogRead(YJOY);
 int joystickB = digitalRead(BUTTON_JOY);

 Serial.print("X:");
 Serial.print(((joystickX+520)/10)-103);
 Serial.print("Y:");
 Serial.print(((joystickY+520)/10)-103);
 Serial.print("B:");
 Serial.print(joystickB);
 Serial.print("  ");
 Serial.println();

 delay(50);
}
