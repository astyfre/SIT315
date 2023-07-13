// C++ code
int TempSensor = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(TempSensor, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  int tempRead = analogRead(TempSensor);
  float voltage = tempRead * 5.0;
  voltage /= 1024.0;
  
  float temperatureC = (voltage -0.5) * 100;
  
  delay(3000);
  
  if (temperatureC > 30) {
    Serial.print(" temp is hot: ");
    Serial.print(temperatureC);
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    delay(100);
  }
  if ((temperatureC >= 5) && (temperatureC <= 30)) {
    Serial.print(" temp is comfortable: ");
    Serial.print(temperatureC);
    digitalWrite(11,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    delay(100);
  }
  if (temperatureC < 5) {
    Serial.print(" temp is cold: ");
    Serial.print(temperatureC);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(13,LOW);
    delay(100);
    
  }
  delay(100);
}