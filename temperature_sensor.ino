/**
  This project determines body temperature using a temperature sensor. Three
  LEDs are on the breadboard where each is lit when body temperature exceeds
  baseline room temperature by 2, 4 and 6 degrees, respectively.
**/

const int SENSOR_PIN = A0;          // analog input
const float BASELINE_TEMP = 20.31;  // baseline temperature

void setup() {
  Serial.begin(9600);               // open a serial port
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);     // configure pins 2 thru 4 as output pins
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
   // get value from sensor
   // value will be between 0 and 1023, which represents voltage on pin
  int sensorVal = analogRead(SENSOR_PIN);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // convert ADC reading to voltage (between 0V and 5V)
  float voltage = (sensorVal/1024.0) * 5.0;
  
  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees F: ");
  // convert voltage to temperature in degrees
  float temperature = (voltage - 0.5) * 100;
  // print temperature in degrees Fahrenheit
  Serial.println((temperature * 1.8) + 32);

  if (temperature < BASELINE_TEMP + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if ((temperature >= BASELINE_TEMP + 2) && (temperature < BASELINE_TEMP + 4)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if ((temperature >= BASELINE_TEMP + 4) && (temperature < BASELINE_TEMP + 6)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (temperature >= BASELINE_TEMP +6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(5);

}
