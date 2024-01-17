#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int speaker = 8;              // speaker at pin 8
const int totalNumNotes = 28; // total notes in song (including pauses)

// ------NOTES & SCALES-----//
int pause = 0;   // no frequency (0 Hz)
int D3 = 146;
int E3 = 164;
int G3 = 196;
int FS3 = 185;
int noteA3 = 220; // 'A3' by itself is A3 on Arduino
int B3 = 246;
int C4 = 261;
int D4 = 293;

int melody[totalNumNotes] = {
  D3, D3, E3, D3, G3, FS3, pause,     // verse 1
  D3, D3, E3, D3, noteA3, G3, pause,  // verse 2
  D3, D3, D4, B3, G3, FS3, E3, pause, // verse 3
  C4, C4, B3, G3, noteA3, G3};        // verse 4

// 4 followed by 2 is an eigth note
// 8 is a quarter note
// 16 is a half note
// 60 is what I used to represent the length of pause
int noteLen[totalNumNotes] = {
  4,2,8,8,8,16,60,   // verse 1
  4,2,8,8,8,16,60,   // verse 2
  4,2,8,8,8,8,16,60, // verse 3
  4,2,8,8,8,16};     // verse 4

int tempo = 65;

void play(int pitch, int duration) {
  tone(speaker, pitch);
  delay(duration);
  noTone(speaker);
}

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Happy Birthday");
  lcd.setCursor(0,1);
  lcd.print("    Mom! <3");
  pinMode(13, OUTPUT); // red LED
  pinMode(9, OUTPUT);  // yellow LED
  pinMode(6, OUTPUT);  // green LED
  pinMode(10, OUTPUT); // blue LED
}

void loop() {
  for (int i = 0; i < totalNumNotes; i++) {
    digitalWrite(13, LOW);
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
    if (melody[i] != pause) {
      if (melody[i] == D3 || i == 20 || i == 25) {  // turn on red LED
        digitalWrite(13, HIGH);
      }
      if ((melody[i] == E3 && i != 20) || melody[i] == FS3 ||
          i == 12 || i == 18 || i == 24 || i == 26) { // turn on yellow LED
            digitalWrite(9, HIGH);
      }
      if (melody[i] == C4 || i == 4 || i == 11 || i == 17) { // turn on green LED
            digitalWrite(6, HIGH);
      }
      if (melody[i] == D4) {  // turn on blue LED
        digitalWrite(10, HIGH);
      }
      if (i == 27) { // final note of melody all LEDs are lit
        digitalWrite(13, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(10, HIGH);
      }
      play(melody[i], noteLen[i]*tempo);
      delay(tempo);
    }
    else {  // there is a pause
      delay(noteLen[i]);
    }
  }
}

