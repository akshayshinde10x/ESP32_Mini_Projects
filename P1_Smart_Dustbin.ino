// Smart Dustbin Pin Connection with Arduino
// Arduino Pin 3  - Motor Yellow Wire
// Arduino 5V     - Motor Red Wire
// Arduino GND    - Motor Brown Wire

// Arduino Pin 2  - Sensor O/P Pin
// Arduino 3.3V   - Sensor VCC Pin
// Arduino GND    - Sensor GND

#include <Servo.h> 

int LED=13;
int servoPin = 3; 
Servo Servo1; 

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
   Servo1.attach(servoPin); 
}
void loop() {
  int val=digitalRead(2);
  Serial.println(val);
  if(val<1)
 {
   digitalWrite(LED,HIGH);
   Servo1.write(90); 
   Serial.println("Open");
    delay(1000); 
  }
  else
  {
    digitalWrite(LED,LOW);
    Servo1.write(0); 
    Serial.println("Close");
    delay(1000); 
  }
  Serial.println(val);
}
