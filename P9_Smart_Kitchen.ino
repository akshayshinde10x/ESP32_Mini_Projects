#include "DHT.h"
#define DHT11PIN 12
DHT dht(DHT11PIN, DHT11);

int fan_relay_pin = 14;
void setup()
{
  pinMode(fan_relay_pin, OUTPUT);
  pinMode(DHT11PIN, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("ºC ");
  Serial.print("Humidity: ");
  Serial.println(humi);
  delay(1000);

  if(temp>32) {
    digitalWrite(fan_relay_pin,HIGH);
    Serial.println("Fan is ON");    
  } else {
    digitalWrite(fan_relay_pin,LOW); 
    Serial.println("Fan is PFF");  
  }
}