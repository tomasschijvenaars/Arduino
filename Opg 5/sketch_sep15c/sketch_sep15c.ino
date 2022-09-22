int redPin= 9;
int greenPin = 6;
int bluePin = 5;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop() {
  for(int red = 0; red < 17; red++)
  {
    analogWrite(redPin, red * 15);
    delay(50);
    for(int blue = 0; blue < 17; blue++)
    {
      analogWrite(bluePin, blue * 15);
      delay(50);
      for(int green = 0; green < 17; green++)
      {
        analogWrite(greenPin, green * 15);
        delay(50);
      }
    }  
  }
}
