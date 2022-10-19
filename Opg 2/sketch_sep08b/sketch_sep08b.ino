//led pin en buttonpin aanspreken
const int ledPin = 11;         
const int buttonPin = 4;

int buttonState = 0;          //variabele om button te lezen

void setup() {
  pinMode(ledPin, OUTPUT);    //Ledpin aanspreken
  pinMode(buttonPin, INPUT);  //Buttonpin aanspreken
}

void loop() {
  
  buttonState = digitalRead(buttonPin); //state van de button lezen

  if (buttonState == HIGH) {            //check of er op de button is gedrukt, als buttonstate high is is er gedrukt
    //led uitlezen, aanzetten als hij uitstaat en andersom
    if(digitalRead(ledPin) == LOW){
    digitalWrite(ledPin, HIGH);
    delay(500);
    }else{
      digitalWrite(ledPin, LOW);
      delay(500);
    }
  }
}
