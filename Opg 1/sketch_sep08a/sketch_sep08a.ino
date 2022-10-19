int timer = 100;           // nummer voor timing
void setup() {
  //pinmode voor alle pins op output zetten
  for (int thisPin = 2; thisPin < 10; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}


void loop() {
  // loop van hoogste naar laagste pin
  // for loop om met de lampjes naar rechts te gaan
  for (int thisPin = 2; thisPin < 10; thisPin++) {
    //HIGH is aan, LOW is uit
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin, LOW);
  }
  //for loop om met de lampjes naar links te gaan
  for (int thisPin = 9; thisPin >= 2; thisPin--) {
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin, LOW);
  }
}
