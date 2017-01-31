#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"
#include <SoftwareSerial.h>
int rightMotor1 = 10;  //rightMotor1
int rightMotor2 = 11;  //rightMotor2
int leftMotor1 = 12;  //leftMotor1
int leftMotor2 = 13;  //leftMotor2
int buzzer = 8;

char command;
String string;


void setup()
{
    Serial.begin(9600);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  if (Serial.available() < 1) return;
  if (Serial.available() > 0) 
    {string = "";}
    
    while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
        Serial.println(Serial.read());
      if(command == ':')
      {
        break;
      }
      
      else
      {
        string += command;
      }
      
      delay(1);
    }


  
  if(string == "UP") runMotor(HIGH,LOW,HIGH,LOW); //straight  
  if(string == "DOWN") runMotor(LOW,HIGH,LOW,HIGH); //backward
  if(string == "RIGHT") runMotor(HIGH,LOW,LOW,LOW); //right
  if(string == "LEFT") runMotor(LOW,LOW,HIGH,LOW);  //left
  if(string == "TOPRIGHT") runMotor(HIGH,LOW,LOW,HIGH); // TOP RIGHT
  if(string == "TOPLEFT") runMotor(LOW,HIGH,HIGH,LOW); //TOP LEFT
  if(string == "BOTTOMLEFT") runMotor(LOW,LOW,LOW,HIGH);
  if(string == "BOTTOMRIGHT") runMotor(LOW,HIGH,LOW,LOW);
  if(string == "MIDDLE") digitalWrite(buzzer, HIGH);
  if(string == "STOP") runMotor(LOW,LOW,LOW,LOW);

    
}


void runMotor(boolean left1,boolean left2,boolean right1,boolean right2)
{
    digitalWrite(rightMotor1, right1); 
    digitalWrite(rightMotor2, right2);  
    digitalWrite(leftMotor1, left1); 
    digitalWrite(leftMotor2, left2);
    digitalWrite(buzzer, LOW);

}