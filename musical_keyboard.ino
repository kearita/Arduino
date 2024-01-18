int notes[] = {262, 294, 330, 523}; // represents frequencies of notes C4, D4, E4 and C5 (in Hz)
void setup() {
  Serial.begin(9600); // start serial comm with computer
}

void loop() {
  int keyVal = analogRead(A0); // holds value read on pin A0
  Serial.println(keyVal); // for testing purposes
  if (keyVal == 1023) {
    tone(8, notes[0]); // pin 8, play C4
  }
  else if (keyVal >= 990 && keyVal <= 1010) {
    tone(8, notes[1]); // play D4
  }
  else if (keyVal >= 505 && keyVal <= 515) {
    tone(8, notes[2]); // play E4
  }
  else if (keyVal >= 960 && keyVal <= 970) {
    tone(8, notes[3]); // play C5
  }
  else {
    noTone(8); // no button is pressed
  }
}
