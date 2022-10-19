#include <Servo.h>
//trigger en echo van de sensor aanspreken
const int trigPin = 12;
const int echoPin = 8;
//servo pin aanspreken
const int servoPin  = 9; 

Servo servo;

//waardes om getallen in op te slaan
float pulse;
float distance;

int angle = 0;

void setup(){
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  servo.attach(servoPin);
}

void loop(){
  //trigger aan en uitzetten voor 10 microseconde
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  pulse = pulseIn(echoPin, HIGH);
  //distance naar cm
  distance = pulse / 58;
  Serial.print("Afstand: ");
  Serial.print(distance);
  Serial.println("cm");
  //kijken of distance tussen 10 en 4 cm zit
  if(distance < 10 && distance >4) {
    Serial.println("Minder dan 10cm");
  servo.write(20);
  }
  //kijken of cm kleiner dan 4cm is
  if(distance < 4) {
    Serial.println("Minder dan 4 cm");
  servo.write(180);
  }
  //delay zodat het soepeler loopt
  delay(100);
}
