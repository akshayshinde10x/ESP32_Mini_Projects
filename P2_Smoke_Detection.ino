//Smoke Detection Using Gas Sensor
// A1 Pin  - Sensor A0
// 6 Pin   - Red LED
// 7 Pin   - Green LED
// 10 Pin  - Buzzer  	

int redLed = 6;
int greenLed = 7;
int buzzer = 10;
int sensorThres = 300;
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
    Serial.println("Smoke Detected");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    Serial.println("Smoke Not Detected");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer, LOW);
  }
  delay(2000);
}
