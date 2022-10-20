//elementen aangeven
const int ledGreen = 4;
const int ledYellow = 3;
const int ledRed = 2;
const int btnPin = 11;

int buttonState = 0;
//ints waarin random nummer wordt opgeslagen
int timeGreen;
int timeRed;

int ledStatus = 0;

unsigned long timer;
//bool of de knop is ingedrukt
bool isPressed = false;

void setup()
{
  //pinmodes instellen
  pinMode(btnPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  //serial aanzetten om println te lezen
  Serial.begin(9600);
}

void loop()
{
  //millis aanzetten om berekeningen met tijd te doen 
  unsigned long timeNow = millis();
  
  buttonState = digitalRead(btnPin);
  //als er op de knop geklikt wordt de buttonstate veranderen naar aan of uit
  //bij aan gaat hij alle kleuren af, bij uit knippert hij geel
  if(buttonState == HIGH)
  {
    if(isPressed == false)
    {
      isPressed = true;
      timer = millis();
    }else
    {
     isPressed = false;
     timer = millis();
    }
    Serial.println(isPressed);
  }
  
  if (isPressed == true)
  {
    Serial.println("in ispressed");
    //random tijd voor de lichtjes
    timeGreen = random(8000,15000);
    timeRed = random(8000,15000);
    
    //van groen naar geel naar rood gaan
    if(timeNow - timer <= timeGreen){
      Groen();
    }else{
    
      if(timeNow - timer <= (timeGreen + 3000)){
        Geel(); 
      }else
      {
        if(timer != 0 && timeNow - timer <= (timeGreen + 3000 + timeRed))
        {
           Rood(); 
        }else
        {
           Niks();  
        }
     }
      
    }
  }else
  {
    //het gele knipperende lampje
    if(timeNow - timer >= 1000){
      Serial.println("in else");
    //led aanpassen als het tijd is
    timer = timeNow;
    //als hij aan staat gaat hij uit en andersom
    ledStatus = (ledStatus == LOW) ? HIGH : LOW;
    //status naar de led sturen
    digitalWrite(ledYellow, ledStatus);
    }
  }
  //delay zodat button niet te gevoelig is
  delay(300);
}

//lightjes aan en uit zetten
void Groen()
{
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
}

void Geel()
{
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledRed, LOW);
}

void Rood()
{
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, HIGH);
}
void Niks()
{
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
}
  
