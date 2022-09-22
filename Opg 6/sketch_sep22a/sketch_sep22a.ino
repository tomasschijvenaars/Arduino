#include <Servo.h>

// constants won't change
const int btnPin1 = 7; // Arduino pin connected to button's pin
const int btnPin2 = 4; // Arduino pin connected to button's pin
const int servoPin  = 9; // Arduino pin connected to servo motor's pin

Servo servo; // create servo object to control a servo

// variables will change:
int angle = 0;          // the current angle of servo motor
int lastButtonState1;    // the previous state of button
int currentButtonState1; // the current state of button
int lastButtonState2;    // the previous state of button
int currentButtonState2; // the current state of button

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(btnPin1, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(btnPin2, INPUT_PULLUP);
  servo.attach(servoPin);           // attaches the servo on pin 9 to the servo object

  servo.write(angle);
}

void loop() {
  delay(100);
  boolean btn1 = false;
  boolean btn2 = false;
  
  lastButtonState1    = currentButtonState1;      // save the last state
  currentButtonState1 = digitalRead(btnPin1); // read new state
  
  lastButtonState2    = currentButtonState2;      // save the last state
  currentButtonState2 = digitalRead(btnPin2); // read new state

  if(lastButtonState1 == HIGH && currentButtonState1 == LOW){
    btn1 = true;
  }

  if (lastButtonState2 == HIGH && currentButtonState2 == LOW){
    btn2 = true;
  }
  

  if(btn1 == true && btn2 == false) {
    Serial.println("The button is pressed");

    for(int pos = 0; pos <= 120; pos += 12){
     Serial.print(pos);
     Serial.println("test");
     servo.write(pos);
     delay(100);
    }
    for(int pos = 120; pos >= 0; pos -= 12){
     Serial.print(pos);
     Serial.println("test");
     servo.write(pos);
     delay(100);
    }
  }
  if(btn1 == false && btn2 == true) {
    Serial.println("The button2 is pressed");

    for(int pos = 0; pos <= 120; pos += 24){
     Serial.print(pos);
     Serial.println("test");
     servo.write(pos);
     delay(100);
    }
    for(int pos = 120; pos >= 0; pos -= 24){
     Serial.print(pos);
     Serial.println("test");
     servo.write(pos);
     delay(100);
    }
  }
  if(btn1 == true && btn2 == true) {
    Serial.println("Both buttons pressed");

    for(int pos = 0; pos <= 120; pos += 12){
     Serial.print(pos);
     Serial.println("test");
     servo.write(pos);
     delay(100);
    }
    delay(2000);
    for(int pos = 120; pos >= 0; pos -= 12){
     Serial.print(pos);
     Serial.println("test");
     servo.write(pos);
     delay(100);
    }
  }
}
