  
void setup()
{
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  float duration;
  float distance;
  int x;
  
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  delayMicroseconds(2);
  digitalWrite(6, HIGH);
  delayMicroseconds(5);
  digitalWrite(6, LOW);
  
  pinMode(6, INPUT);
  duration = pulseIn(6, HIGH);
  distance = microsecondsToCentimeters(duration);
  
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  
  x=map(distance,2,340,0,255);//Minimum measurable distance is 2cm and maximun is 330cm.
  Serial.print(x);
  Serial.println();
  analogWrite(3,x);
  analogWrite(5,x);
  delay(1000);}
    
  float microsecondsToCentimeters(float microseconds) {
  return microseconds / 29 / 2;
}
  
  
  
  