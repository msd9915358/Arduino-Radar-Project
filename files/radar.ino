#include <Servo.h>
const int TRIG=10;
const int ECHO=9;
const int MOTOR=6;
const int BUZZER=11;
long DUR;
int DIS;
Servo SERVO;

void setup()
{
  Serial.begin(9600);  
  pinMode(MOTOR,OUTPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(BUZZER,OUTPUT);
  SERVO.attach(MOTOR);
}

void loop()
{
  for(int pos=90;pos<180;pos++)  //rotation cycle 1
  {
    SERVO.write(pos);
    DIS=calcDis();               //calling the calculate distance function
    Serial.println(DIS);
    if(DIS<20)                   //checking if any object is nearby and making sound
    tone(BUZZER,DIS);
    else                         //there is no object nearby
    noTone(BUZZER); 
    delay(100);
  }

  for(int pos=180;pos>=90;pos--)  //rotation cycle 2
  {
    SERVO.write(pos);
    DIS=calcDis();
    Serial.println(DIS);
    if(DIS<20)
    tone(BUZZER,DIS);
    else
    noTone(BUZZER);
    delay(100);
  }
}

int calcDis()  //function to calculate distance from the sensor
{
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW); 
   float lecture_echo = pulseIn(ECHO, HIGH); 
  float cm = lecture_echo / 58; 
  return cm;
}
