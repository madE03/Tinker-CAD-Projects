//Program to control the change the speed of motor based on the distance of the obstacle in the room. If the distance of the body is greater
//than 150 cm then the motor runs at 5506 rpm and displays 'No danger'. If the distance detected is less than 150 cm then the motor will run at half the speed and display
//'Danger' in the LCD display.

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//rs, en, d4, d5, d6, d7

void setup()
{
  pinMode(6, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600); //Accessing serial monitor 
}

void loop()
{
  float distance;
  distance =distancecalculator();
  
  lcd.setCursor(4,0); //centering the cursor in the middle
  
  Serial.print(distance); //printing values in serial monitor
  Serial.print("cm");
  Serial.println();
  
  if (distance>=150){
    digitalWrite(6,HIGH);
    lcd.print("No Danger!!");
    delay(1000);
    digitalWrite(6,LOW);
    lcd.clear();}
  
  else{
    lcd.print("Danger!!");
    analogWrite(6,128);
    delay(1000);
    analogWrite(6,0);
    lcd.clear();} 
}

float distancecalculator(){
  //function to calculate distance
  float duration;
  int x;
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(5);
  digitalWrite(7, LOW);
  
  pinMode(7, INPUT);
  duration = pulseIn(7, HIGH);
  return duration/29/2;}
  
