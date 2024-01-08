/**
  This program uses pulse width modulation to fade LEDs. Phototransistors are used to generate 
  a current proportional to quantity of light absorbed. When the phototransistors are covered
  by a gel, they only react to light of a certain wavelength. 
**/

const int GREEN_LED = 9;
const int RED_LED = 10;
const int BLUE_LED = 11;

// analog-in sensor pins
const int RED_SENSOR = A0;
const int GREEN_SENSOR = A1;
const int BLUE_SENSOR = A2;

int redVal = 0;
int greenVal = 0;
int blueVal = 0;

int redSensorVal = 0;
int greenSensorVal = 0;
int blueSensorVal = 0;
void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop() {
  redSensorVal = analogRead(RED_SENSOR);
  delay(5); // ADC requires a ms of time
  greenSensorVal = analogRead(GREEN_SENSOR);
  delay(5);
  blueSensorVal = analogRead(BLUE_SENSOR);
  Serial.print("Raw sensor values \t red: ");
  Serial.print(redSensorVal);
  Serial.print("\t green: ");
  Serial.print(greenSensorVal);
  Serial.print("\t blue: ");
  Serial.println(blueSensorVal);

  // need to convert to a value between 0 - 255 for analogWrite()
  redVal = redSensorVal/4;
  greenVal = greenSensorVal/4;
  blueVal = blueSensorVal/4;
  
  Serial.print("Mapped sensor values \t red: ");
  Serial.print(redVal);
  Serial.print("\t green: ");
  Serial.print(greenVal);
  Serial.print("\t blue: ");
  Serial.println(blueVal);

  analogWrite(RED_LED, redVal);
  analogWrite(GREEN_LED, greenVal);
  analogWrite(BLUE_LED, blueVal);

}

