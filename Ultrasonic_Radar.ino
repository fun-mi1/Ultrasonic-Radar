#include <Servo.h>

int servopin = 12;
int angle = 0;
Servo myservo;
int trigpin = 9;
int echopin = 10;
long distance, duration;

void setup() {
Serial.begin(9600);
myservo.attach(servopin);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);

}

//Creation of the function that gets the distance from the ultrasonic sensor
long getdist(){
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);  

  duration = pulseIn(echopin, HIGH);
  distance = (duration * 0.0343)/2;
  return distance;
    
}

void loop() {
//Foward Sweep
for(angle = 0; angle <= 180; angle += 2){
  myservo.write(angle);
  delay(20);
  long dist = getdist();
  Serial.print(angle);
  Serial.print(",");
  Serial.println(dist);
  delay(200);
}
//Backward Sweep
for(angle = 180; angle >= 0; angle -= 2){
  myservo.write(angle);
  delay(20);
  long dist = getdist();
  Serial.print(angle);
  Serial.print(",");
  Serial.println(dist);
  delay(200);
}

}
