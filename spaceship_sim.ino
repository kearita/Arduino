/**
  This program simulates a spaceship. Green light is constantly lit. When we need to activate 
  the lasers we press the 'fire' button and lasers shoot until button is no longer pressed.
**/
void setup() {
  pinMode(3, OUTPUT); // green LED
  pinMode(4, OUTPUT); // red LED
  pinMode(5, OUTPUT); // red LED
  pinMode(2, INPUT); // push button
}

void loop() {
  int switchState = 0;
  switchState = digitalRead(2);
  if (switchState == LOW) { // open switch/button not pressed
    digitalWrite(3, HIGH); // green LED is lit
    digitalWrite(4, LOW); // red LED off
    digitalWrite(5, LOW); // red LED off
  }
  else { // button is pressed
    digitalWrite(3, LOW); // green LED off
    digitalWrite(4, LOW); // red LED 1 is off initially
    digitalWrite(5, HIGH); // red LED 2 is lit

    delay(250); // wait for a quarter of a second
    //now toggle the red LEDs back and forth
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  }

}
