#include <LiquidCrystal.h>

const int dry = 700; // represents MIN soil moisture level (needs to be calibrated)
const int wet = 500; // represents MAX soil moisture level (needs to be calibrated)
LiquidCrystal lcd(12,11,5,4,3,2);

// < 500 too wet
  // 500 - 750 good
  // > 750 dry -- needs to be watered

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

int getPercent(int value) {
  int percentage = map(value, wet, dry, 100, 0);
  return percentage;
}

void loop() {
  int moistureLevel = analogRead(A0);
  int moisturePercent = getPercent(moistureLevel);
  Serial.print("Analog output: ");
  Serial.println(moistureLevel);
  
  if (moistureLevel < wet) {
    Serial.println("Status: soil is too wet");
  }
  else if (moistureLevel >= wet && moistureLevel < dry) {
    Serial.println("Status: soil moisture is good");
  }
  else {
    Serial.println("Status: soil is too dry -- need to water");
  }
  lcd.setCursor(0,0);
    lcd.print("Level: ");
    lcd.setCursor(0, 1);
    lcd.print(moistureLevel);
    lcd.setCursor(0, 1);
    lcd.print("Moisture %: ");
    lcd.println(moisturePercent);
  delay(500);
  Serial.println();
}
