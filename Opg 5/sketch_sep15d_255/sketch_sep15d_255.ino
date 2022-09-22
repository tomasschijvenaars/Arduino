int redPin= 9;
int greenPin = 6;
int bluePin = 5;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop() {
  for(int red = 0; red < 255; red++)
  {
    analogWrite(redPin, red);
    delay(50);
    for(int blue = 0; blue < 255; blue++)
    {
      analogWrite(bluePin, blue);
      delay(50);
      for(int green = 0; green < 17; green++)
      {
        analogWrite(greenPin, green);
        delay(50);
      }
    }  
  }
}
