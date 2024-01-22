const int switchPin = 8; // tilt sensor location
unsigned long prevTime = 0; // holds time an LED was last changed
int switchState = 0; // compare switch's position from one loop to next
int prevSwitchState = 0;
int led = 2; // which LED is next to be turned on starting with pin 2
long interval = 600000; // interval between each LED being turned on -- 600000 ms in 10 mins
void setup() {
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currTime = millis(); // amount of time Arduino has been running
  if (currTime - prevTime > interval) {
    prevTime = currTime;
    digitalWrite(led, HIGH);
    led++;
    if (led == 7) {
      Serial.print("1 hour has passed!");
    }
  }
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) { // if different, turn LEDs off
    for (int i = 2; i < 8; i++) {
      digitalWrite(i, LOW);
    }
    led = 2;
    prevTime = currTime;
  }
  prevSwitchState = switchState;
}

