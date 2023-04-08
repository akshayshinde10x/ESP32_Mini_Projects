int MQ_2 = 13;
int MQ_6 = 12;
int MQ_135 = 14;
int MQ_2_value;
int MQ_6_value;
int MQ_135_value;

void setup ()
{
  pinMode(MQ_2,INPUT);
  pinMode(MQ_6,INPUT);
  pinMode(MQ_135,INPUT);
  Serial.begin(9600);
 
}
void loop ()
{
   MQ_2_value = analogRead(MQ_2);
  MQ_6_value = analogRead(MQ_6);
  MQ_135_value=analogRead(MQ_135);
Serial.print("MQ_2_value:");
Serial.print(MQ_2_value);
Serial.println();
Serial.print("MQ_6_value:");
Serial.print(MQ_6_value);
Serial.println();
Serial.print("MQ_135_value:");
Serial.print(MQ_135_value);

Serial.println();
delay(5000);

}