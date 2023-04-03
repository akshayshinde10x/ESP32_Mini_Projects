//Water Tank Level Monitoring with ThingSpeak

#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti WiFiMulti;

const char* ssid     = "Mobile"; // Your SSID (Name of your WiFi)
const char* password = "123456789"; //Your Wifi password

const char* host = "api.thingspeak.com";
String api_key = "04NXTNQ2T7BYIDFD"; // Your API Key provied by thingspeak

const int trigPin = 5; //GPIO5
const int echoPin = 18; //GPIO18

#define SOUND_SPEED 0.034
#define tank_Height 10.00

long duration;
float distanceCm;
float percentage;

void setup(){
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Connect_to_Wifi();
}

void loop(){
  percentage = (tank_Height - getSensorData ()) * 10;
 
  Serial.print("Water filled in Tank: "); 
  Serial.print(percentage);
  Serial.println(" %");
  delay(1000);
  
  Send_Data(percentage);
  delay(5000);
}

void Connect_to_Wifi()
{
  WiFiMulti.addAP(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

float getSensorData(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED/2;

  Serial.print("Water at Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  return distanceCm;   
}

void Send_Data(float waterLevel){
  Serial.println("");
  Serial.println("Prepare to send data");

  WiFiClient client;
  const int httpPort = 80;

  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  else
  {
    String data_to_send = api_key;
    data_to_send += "&field1=";
    data_to_send += String(waterLevel);
    data_to_send += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + api_key + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(data_to_send.length());
    client.print("\n\n");
    client.print(data_to_send);

    delay(1000);
  }

  client.stop();
}
