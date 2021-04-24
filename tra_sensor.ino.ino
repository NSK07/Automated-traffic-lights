//SOURCE CODE.............

#include <NewPing.h>
#define trigPin 13
#define echoPin 12
#define led3 11 
#define led4 10
#define trigPin2 3 
#define echoPin2 2
#define led 4
#define led2 5
#define led5 7 
#define led6 8
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop() {
  long duration, distance,duration2, distance2;
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led6,LOW);
  digitalWrite(led5,HIGH);
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance<10) 
  {  
    digitalWrite(led,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
     digitalWrite(led5,LOW);
     digitalWrite(led6,HIGH);
  }
  else{
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  delay(2000);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;
  if(distance2<10) { 
    digitalWrite(led4,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led5,LOW);
    digitalWrite(led6,HIGH);
  } 
  else {
    digitalWrite(led4,LOW);
    digitalWrite(led3,HIGH);
  }
  delay(2000);
  if (distance>=200 || distance<=0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(2000);
}

