#include <Servo.h>

const int trigPin = 9; // TRIG ke pin 9
const int echoPin = 10; // ECHO ke pin 10

long duration;
int distance;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(13); 
}
void loop() {
  for(int i=0;i<=180;i++){  // Servo berputar 180 derajat
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  
  Serial.print(i);
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
  }

  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}