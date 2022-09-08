int timer = 100;           // nummer voor timing
void setup() {
  for (int thisPin = 2; thisPin < 10; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}


void loop() {


  // loop from the lowest pin to the highest:


  for (int thisPin = 2; thisPin < 10; thisPin++) {
    //HIGH is aan, LOW is uit
    digitalWrite(thisPin, HIGH);

    delay(timer);

    digitalWrite(thisPin, LOW);
  }

  for (int thisPin = 9; thisPin >= 2; thisPin--) {

    digitalWrite(thisPin, HIGH);

    delay(timer);

    digitalWrite(thisPin, LOW);

  }

}
