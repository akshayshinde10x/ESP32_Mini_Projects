// Automated Pet Feeding System
#include <Servo.h> 

int IR=2;
int servoPin1 = 4;
int servoPin2 = 5; 
int WaterSensor = A1;

Servo Servo1;
Servo Servo2; 

void setup() {
  Serial.begin(9600);
  pinMode(IR,INPUT);
  pinMode(WaterSensor,INPUT);
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2); 
}
void loop() {
  int val=digitalRead(2);
  Serial.println(val);
  if(val<1)
 {
   Servo1.write(90);
   Servo2.write(90); 
   Serial.println("Open");
    delay(1000); 
  }
  else
  {
    Servo1.write(0);
    Servo2.write(0); 
    Serial.println("Close");
    delay(1000); 
  }
  Serial.println(val);
}