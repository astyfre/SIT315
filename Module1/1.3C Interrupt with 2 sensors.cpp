// C++ code

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(2), move, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), press, CHANGE);
}

void loop()
{
  Serial.print(" 1 second ");
  delay (1000);
  Serial.print(" 2 seconds ");
  delay(1000);
  Serial.print(" 3 seconds ");
  delay (1000);
   Serial.print(" 4 second ");
  delay (1000);
  Serial.print(" 5 seconds ");
  delay(1000);
  Serial.print(" 6 seconds ");
  delay (1000);
   Serial.print(" 7 second ");
  delay (1000);
  Serial.print(" 8 seconds ");
  delay(1000);
  Serial.print(" 9 seconds ");
  delay (1000);
}

void move(){
  int movement = digitalRead(2);
  
   if (movement == HIGH) {
    Serial.print(" movement detected ");
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  if (movement == LOW) {
    Serial.print(" No movement detected ");
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);   
  }
}

void press(){
  int button = digitalRead(3); // ler estadobotao
  
  if(button == HIGH)
  {
    Serial.print("Button down");
    digitalWrite(11, HIGH);
  } else {
    Serial.print("Button up");
    digitalWrite(11, LOW);
  }
  
}