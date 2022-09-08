//set pin numbers
const int ledPin = 11;         
const int buttonPin = 4;

//variables will change
int buttonState = 0;          //variabele om button te lezen

void setup() {

  pinMode(ledPin, OUTPUT);    //Ledpin aanspreken
  pinMode(buttonPin, INPUT);  //Buttonpin aanspreken
}

void loop() {
  
  buttonState = digitalRead(buttonPin); //state van de button lezen

  if (buttonState == HIGH) {            //check if the pushbutton is pressed
    //if it is, the buttonState is HIGH
    if(digitalRead(ledPin) == LOW){
    digitalWrite(ledPin, HIGH);
    delay(500);
    }else{
      digitalWrite(ledPin, LOW);
      delay(500);
    }
  }
}
