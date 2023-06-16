#include<Servo.h>

Servo servo;

int sensorPin0 = A0;    //irsensor
int sensorPin1 = A1;    //irsensor
int sensorPin2 = A2;    //irsensor
int sensorPin3 = A3;    //irsensor
int out2 = 2; //r1
int out3 = 3; //g1
int out4 = 4; //r2
int out5 = 5; //g2

int sensorValue0 = 0;
int sensorValue1 = 0;
int outputValue2 = 0;
int sensorValue2 = 0;
int outputValue3 = 0;
int sensorValue3 = 0;
int servopin = 9;       //servo

void setup() {
  Serial.begin(9600);
  servo.attach(servopin);
  servo.write(0);
}

void loop() {
  sensorValue0 = analogRead(sensorPin0);  //servo
  sensorValue1 = analogRead(sensorPin1);  //servo
  sensorValue2 = analogRead(sensorPin2);  //led
  sensorValue3 = analogRead(sensorPin3);  //led
  Serial.println(sensorValue0);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
  outputValue3 = map(sensorValue3, 0, 1023, 0, 255);
  sensorValue0 = map(sensorValue0, 0, 1023, 0, 179);
  sensorValue1 = map(sensorValue1, 0, 1023, 0, 179);

  if((sensorValue0 <100) || (sensorValue1 < 100)){
    if(sensorValue0 < 100){
      servo.write(sensorValue0);
      delay(1000);
       Serial.println("Entry");
    }
    if(sensorValue1 < 100){
      servo.write(sensorValue1);
      delay(1000);
       Serial.println("Exit");
    }
  }else{
    servo.write(sensorValue0);
    delay(1000);
    Serial.println("Door closed");
  }
  
  if(sensorValue2 < 200){
    analogWrite(2, 255);
    analogWrite(3, 0);
    Serial.println("Car parked");
  }else{
    analogWrite(3, 255);
    analogWrite(2, 0);
    Serial.println("Empty slot");
  }
  if(sensorValue3 < 200){
    analogWrite(4, 255);
    analogWrite(5, 0);
    Serial.println("Car parked");
  }else{
    analogWrite(5, 255);
    analogWrite(4, 0);
    Serial.println("Empty slot");
  }
  delay(600);
}
