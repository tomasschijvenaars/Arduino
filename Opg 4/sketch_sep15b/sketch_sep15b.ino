float temp; //variabele voor temperatuur
int tempPin = 0; //temperatuurpin

void setup() {
   Serial.begin(9600);
}

void loop() {
   //sensorwaarde uitlezen en in temp zetten
   temp = analogRead(tempPin);
   // de volt in graden celsius veranderen
   temp = temp * 0.48828125;
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); 
   Serial.print("*C");
   Serial.println();
   delay(1000); // delay van 1 sec zodat om de seconde temperatuur wordt uitgelezen
}
