
int _moisture,sensor_analog;
const int sensor_pin = 13;
const int motor_pump_relay_Pin = 12;  /* Soil moisture sensor O/P pin */

void setup(){
  pinMode(sensor_pin,INPUT);
  pinMode(motor_pump_relay_Pin,OUTPUT);
  Serial.begin(115200);     /* Set the baudrate to 115200*/
}

void loop(){
  sensor_analog = analogRead(sensor_pin);
  _moisture = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
  Serial.print(sensor_analog);
  Serial.print("Moisture = ");
  Serial.print(_moisture);  /* Print Temperature on the serial window */
  Serial.println("%");        /* Wait for 1000mS */
  
  if(40 < _moisture && _moisture < 60) {
    digitalWrite(motor_pump_relay_Pin,HIGH);  
    Serial.println("soil moisture in the range (40 to 60) ");
    Serial.println("Motor Pump is off");
  } else {
    digitalWrite(motor_pump_relay_Pin,LOW);
    Serial.println("Soil Required Water  ");
    Serial.println("Motor Pump is on");
  }
  delay(5000);
}