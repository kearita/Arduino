/**
  This program involves a potentiometer as a voltage divider. As the knob is turned the ratio of voltage
  between the middle pin and power is changed. This controls the position of a servo motor. The 
  servo motor arm rotates a max of 180 degrees. Voltage values from pot are mapped to degree values.
**/

#include <Servo.h>
Servo myServo; // create obj for servo

int const potPin = A0; // potentiometer pin
int potVal; // analog input value
int angle; // angle we want servo to move to

void setup() {
  myServo.attach(9); // lets Arduino know which pin servo is attached to
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179); // map() scales numbers 0-1023 to 0-179
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle); // moves servo to desired angle
  delay(1800); // time to move to new position

}
