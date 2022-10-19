#include <Servo.h>

//constants veranderen niet 
const int btnPin1 = 7; 
const int btnPin2 = 4; 
const int servoPin  = 9; 

Servo servo; // servo object maken om deze te controllen

// variables will change:
int angle = 0;          // angle van de servo
int lastButtonState1;    
int currentButtonState1; 
int lastButtonState2;    
int currentButtonState2; 

void setup() {
  Serial.begin(9600);                
  pinMode(btnPin1, INPUT_PULLUP);   //pullup meet wanneer de knop wordt losgelaten
  pinMode(btnPin2, INPUT_PULLUP);
  servo.attach(servoPin);           //de servo aan pin 9 binden

  servo.write(angle);   //angle op 0 zetten
}

void loop() {
  delay(100);
  boolean btn1 = false; //bools om de dubbele druk te meten
  boolean btn2 = false;
  
  lastButtonState1    = currentButtonState1;      // oude state opslaan
  currentButtonState1 = digitalRead(btnPin1);     // nieuwe state uitlezen
  
  lastButtonState2    = currentButtonState2;      
  currentButtonState2 = digitalRead(btnPin2);     

  //flags zetten voor op welke knop is gedrukt
  if(lastButtonState1 == HIGH && currentButtonState1 == LOW){
    btn1 = true;
  }

  if (lastButtonState2 == HIGH && currentButtonState2 == LOW){
    btn2 = true;
  }
  
  //flags uitlezen en de correcte functie uitvoeren
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
