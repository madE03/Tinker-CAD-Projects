#include <math.h>
void setup()
{
  pinMode(8,INPUT);
  digitalWrite(8,HIGH);
  
  pinMode(11,OUTPUT);
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  Serial.begin(9600);
}
int count=0;

void loop()
{
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
  
  int bi=0;
  int lad=0;
  int j=7;
  
  if (digitalRead(8)==0){
    count+=1;
    Serial.print(count);
    Serial.println();
    bi= dec_to_bin(count);
    Serial.print(bi);
    Serial.println();
    Serial.println();}
  
  if (count<=15){
    analogWrite(11,15-count);}
  
  int bi1=bi;
  
  while (bi1>=1){
    lad=bi1%10;
    bi1/=10;
    if (lad==1){
      digitalWrite(j,HIGH);}
    j-=1;
  }
  
  delay(2000);
  
}
int dec_to_bin(int p){
  int i=1;
  int bin=0;
  int rem=0;
  
  while (p != 0) {
        rem = p % 2;
        p /= 2;
        bin += rem *i;
        i*=10;}
  return bin;
}
  