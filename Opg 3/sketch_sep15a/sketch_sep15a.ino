//onderdelen aanspreken
int potPin = A5;
int Ledpin1 = 2;
int Ledpin2 = 3;
int Ledpin3 = 4;
int Ledpin4 = 5;
int Ledpin5 = 6;
int Ledpin6 = 7;
int Ledpin7 = 8;

void setup()
{
  //wat je van elk onderdeel wil meten
  pinMode(potPin, INPUT);
  pinMode(Ledpin1, OUTPUT);
  pinMode(Ledpin2, OUTPUT);
  pinMode(Ledpin3, OUTPUT);
  pinMode(Ledpin4, OUTPUT);
  pinMode(Ledpin5, OUTPUT);
  pinMode(Ledpin6, OUTPUT);
  pinMode(Ledpin7, OUTPUT);
  //seriele monitor aanzetten
  Serial.begin(9600);
  
  
}

void loop()
{
  //graden van de potmeter uitlezen
  int potMeasure = analogRead(A5);
  //graden in log zetten
  Serial.println(potMeasure);
    //lampjes aan of uitzetten als graden groter of kleiner zijn dan de getallen
    if (potMeasure < 30)
    {
      digitalWrite(Ledpin1, LOW);
      digitalWrite(Ledpin2, LOW);
      digitalWrite(Ledpin3, LOW);
      digitalWrite(Ledpin4, LOW);
      digitalWrite(Ledpin5, LOW);
      digitalWrite(Ledpin6, LOW);
      digitalWrite(Ledpin7, LOW);
    }
    else if (potMeasure < 146)
    {
      digitalWrite(Ledpin1, HIGH);
      digitalWrite(Ledpin2, LOW);
      digitalWrite(Ledpin3, LOW);
      digitalWrite(Ledpin4, LOW);
      digitalWrite(Ledpin5, LOW);
      digitalWrite(Ledpin6, LOW);
      digitalWrite(Ledpin7, LOW);
    }else if (potMeasure < 293)
    {
      digitalWrite(Ledpin1, HIGH);
      digitalWrite(Ledpin2, HIGH);
      digitalWrite(Ledpin3, LOW);
      digitalWrite(Ledpin4, LOW);
      digitalWrite(Ledpin5, LOW);
      digitalWrite(Ledpin6, LOW);
      digitalWrite(Ledpin7, LOW);
    }else if (potMeasure < 439)
    {
      digitalWrite(Ledpin1, HIGH);
      digitalWrite(Ledpin2, HIGH);
      digitalWrite(Ledpin3, HIGH);
      digitalWrite(Ledpin4, LOW);
      digitalWrite(Ledpin5, LOW);
      digitalWrite(Ledpin6, LOW);
      digitalWrite(Ledpin7, LOW);
    }else if (potMeasure < 586)
    {
      digitalWrite(Ledpin1, HIGH);
      digitalWrite(Ledpin2, HIGH);
      digitalWrite(Ledpin3, HIGH);
      digitalWrite(Ledpin4, HIGH);
      digitalWrite(Ledpin5, LOW);
      digitalWrite(Ledpin6, LOW);
      digitalWrite(Ledpin7, LOW);
    }else if (potMeasure < 725){
      digitalWrite(Ledpin1, HIGH);
      digitalWrite(Ledpin2, HIGH);
      digitalWrite(Ledpin3, HIGH);
      digitalWrite(Ledpin4, HIGH);
      digitalWrite(Ledpin5, HIGH);
      digitalWrite(Ledpin6, LOW);
      digitalWrite(Ledpin7, LOW);
    }
    else if (potMeasure < 879)
    {
      digitalWrite(Ledpin1, HIGH);
      digitalWrite(Ledpin2, HIGH);
      digitalWrite(Ledpin3, HIGH);
      digitalWrite(Ledpin4, HIGH);
      digitalWrite(Ledpin5, HIGH);
      digitalWrite(Ledpin6, HIGH);
      digitalWrite(Ledpin7, LOW);
     }else if (potMeasure < 1024)
     {
      digitalWrite(Ledpin1, HIGH);
      digitalWrite(Ledpin2, HIGH);
      digitalWrite(Ledpin3, HIGH);
      digitalWrite(Ledpin4, HIGH);
      digitalWrite(Ledpin5, HIGH);
      digitalWrite(Ledpin6, HIGH);
      digitalWrite(Ledpin7, HIGH);
      }
      
}
