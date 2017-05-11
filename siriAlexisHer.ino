/*

  siriAlexisHer: Turn Me On
  Concept: Robot Fetish & Objectification of Femmes/Cyborgs & SiriAlexisHer

  Assignment: 3-step combination lock

  ,INPUT)
  1. Touch Sensor
  2. Potentiometer
  3. Photo resistor

  ,OUTPUT)
  servo motor
  leds
 
  by Erica Kermani
  @farsiforeplay

*/

#include <Servo.h>

const int touchPin = 4;
const int photoPin = A4;  // flex sensor
const int potPin = A0;

//const int ledPin = 9;
const int ledPin2 = 13;

//Servo myservo;  // create servo object to control a servo

int touchState = 0;
int CURRENT_STATE = 0;
int photoState = 0;
int potVal = 0;
int outputVal = 0; // PWM


//int photoMin = 1023;  // minimum sensor value
//int photoMax = 0;     // maximum sensor value

void setup() {
  Serial.begin(9600);
  
  pinMode(touchPin, INPUT);  // touch will be first nipple
  pinMode(potPin, INPUT);  // potentiometer will be second nipple
//  pinMode(                // wire switch will be pulling hair
//  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

}

void loop() {
//  
  touchState = digitalRead(touchPin);     // reads the value of touch sensor
//  outputValue = map(potVal, 0, 1023, 0, 255);


//   if touchState is 1 aka "touched"
  if (touchState == 1 && CURRENT_STATE == 0) {
    Serial.print("touched");
    Serial.println(touchState);
    CURRENT_STATE = 1;
//    digitalWrite(ledPin2, HIGH);
    potVal = analogRead(potPin);

  }


   if (potVal < 800 && potVal > 100 && CURRENT_STATE == 1) {
    Serial.print("potval: ");
    Serial.println(potVal);
    CURRENT_STATE = 2;
    photoState = analogRead(photoPin);

   }


   if (photoState == 580 && CURRENT_STATE == 2) {
    Serial.print("photoState: ");
    Serial.println(photoState);
    CURRENT_STATE = 3;
    digitalWrite(ledPin2, HIGH);

   }

}
