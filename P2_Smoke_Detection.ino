//Smoke Detection Using Gas Sensor
// A1 Pin  - Sensor A0
// 6 Pin   - Red LED
// 7 Pin   - Green LED
// 10 Pin  - Buzzer  	

int redLed = 6;
int greenLed = 7;
int buzzer = 10;
int sensorThres = 150;
int smoke = A1;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smoke, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smoke);
  
  Serial.print("Pin A1: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
}
