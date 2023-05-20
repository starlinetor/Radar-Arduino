#include <UTFTGLUE.h>     
#include <HCSR04.h>
#include <Servo.h>

//the code uses a lcd screen to write the result
//cahnge the following pin to adapt to you wiring
const int trigPin 22;
const int echoPin 23;
const int servoPin 24;


UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0);
HCSR04 hc(trigPin, echoPin); //initialisation class HCSR04 (trig pin , echo pin) 
Servo myservo;

void setup() {
  randomSeed(analogRead(0));
  myGLCD.InitLCD();
  myservo.attach(servoPin);
}

void loop() {
  myGLCD.clrScr();
  myGLCD.setColor(0, 255, 0);
  for(int i = 0; i< 180; i++){
    myservo.write(i);
    radarLine(i,hc.dist()*0.80);
    delay(60);
  }
}


const int screenResX = 320;
const int screenResY = 240;
float rad;

void radarLine(int angle, float lenght){
  
  rad = angle * 0.01745329;

  myGLCD.drawLine(screenResX/2,screenResY,screenResX/2 + cos(rad)*lenght,screenResY-sin(rad)*lenght);
  return;
}
