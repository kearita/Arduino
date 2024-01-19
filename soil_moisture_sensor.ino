// most sites approximate an ideal humidity level to lie between 40%-60%, but this varies on many factors
// including outside temperature, and the type/age of the plant

#include <LiquidCrystal.h>

const int dry = 650; // represents MIN dry soil moisture level
const int wet = 500; // represents MAX wet soil moisture level
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

// this function is for the purpose of displaying the soil moisture % on LCD screen for quicker viewing
int getPercent(int value) {
  int percentage = map(value, wet, dry, 100, 0);
  return percentage;
}

void loop() {
  int moistureLevel = analogRead(A0);
  int moisturePercent = getPercent(moistureLevel);
  Serial.print("Analog output: ");
  Serial.println(moistureLevel);
  Serial.print("Percent humiditiy: ");
  Serial.print(moisturePercent);
  Serial.println("%");
  
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
  lcd.print("Humidity: ");
  lcd.print(moisturePercent);
  lcd.print("%");
  delay(500);
  Serial.println();
}
