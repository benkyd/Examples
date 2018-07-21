#include <Servo.h>
#define SERVO_PIN 9
#define XJOY_PIN A1
Servo myservo ;
 
void setup()
{
 Serial.begin(9600);
 myservo.attach(9);
}
 
void loop()
{
 delay(200);                    
 int joystickXVal = analogRead(XJOY_PIN) ;  //read joystick input on pin A1
 Serial.print(joystickXVal);                //print the value from A1
 Serial.println(" = input from joystick");  //print "=input from joystick" next to the value
 Serial.print((joystickXVal+520)/10);       //print a from A1 calculated, scaled value
 Serial.println(" = output to servo");      //print "=output to servo" next to the value
 Serial.println() ;
 myservo.write((joystickXVal+520)/10);      //write the calculated value to the servo  
}
