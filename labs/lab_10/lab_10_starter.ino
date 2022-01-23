/* Standard Servomotor sketch
   Bob Wilson
   12/12/2012
   */
   
#include <Servo.h>

Servo myServo;

int potpin = 0;
int val;

void setup() {
  Serial.begin(9600);
  myServo.attach(9); //we will use pin 9
}

void loop() {
  val = analogRead(potpin);
  
  /* take the value of val (should be in the
   * range [0, 1023]) and map it to a value 
   * in the range [0, 180]. 
   * 0 -> 0, 1023 -> 180, 511 -> 90 */
  val = map(val, 0, 1023, 0, 180);
  Serial.println(val);
  
  
  myServo.write(val);
  delay(30);
}