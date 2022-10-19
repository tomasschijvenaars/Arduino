#include <IRremote.h>
//IR pin declareren
const int irPin = 11;
//ledpins declareren
const int ledPin[] = {7,6,5,4};
//knipper delay aangeven, deze wordt aangepast door knop en is dus nu nul
int knip[] = {0, 0, 0, 0};
//laatste keer dat er geknipperd is opslaan, wordt ook aangepast
unsigned long lastTime[] {0,0,0,0};
//bool om de eerste en tweede klik bij te houden
bool click = false;
//geselecteerde led bijhouden
int selectedLed = 0;
// leds uitzetten als standaard
int ledStatus[] = {LOW, LOW, LOW, LOW};

//afstandbediening uitlezen en resulaten decoden
IRrecv irrecv(irPin);
decode_results res;

void setup() {
  Serial.begin(9600);
  //ledpins op output zetten
  for (int thisPin = 0; thisPin < sizeof(ledPin); thisPin++) {
    pinMode(ledPin[(thisPin)], OUTPUT);
  } 
  irrecv.enableIRIn();
}

void loop() {
  //timenow houdt millis bij
  unsigned long timeNow = millis();

  if(irrecv.decode(&res)){
    Serial.println(res.value, HEX);
    irrecv.resume();
    //switch om alle resultaten van de afstandbediening af te gaan van knop 1 t/m 4
    //als click false is is het de eerste klik, hier wordt het lampje geselecteerd
    //als click true is is het de tweede klik, hier wordt de snelheid van het knipperen geselecteerd
    switch(res.value){
      case 0x9716BE3F:
      if(click == false){
        selectedLed = 0;
        click = true;
        Serial.println("first1");
      }else if(click == true){
        knip[selectedLed] = 250;
        click = false;
        Serial.println("second1");
      }
        break;

      case 0x3D9AE3F7:
      if(click == false){
        selectedLed = 1;
        click = true;
        Serial.println("first2");
      }else if(click == true){
        knip[selectedLed] = 500;
        click = false;
        Serial.println("second2");
      }
        break;
      
      case 0x6182021B:
      if(click == false){
        selectedLed = 2;
        click = true;
        Serial.println("first3");
      }else if(click == true){
        knip[selectedLed] = 750;
        click = false;
        Serial.println("second3");
      }
        break;

      case 0x8C22657B:
      if(click == false){
        selectedLed = 3;
        click = true;
        Serial.println("first4");
      }else if(click == true){
        knip[selectedLed] = 1000; 
        click = false;
        Serial.println("second4");
      }
        break;
    }
  }
  //knipperfunctie per lamp
  blink(0);
  blink(1);
  blink(2);
  blink(3);
  //kleine delay zodat hij niet te snel gaat
  delay(100);
}

void blink(int i){
  //Huidige tijd wordt gepakt in milliseconde 
  unsigned long curTime = millis();     
  
  if(curTime - lastTime[i] >= knip[i]){
    //led aanpassen als het tijd is
    lastTime[i] = curTime;
    //als hij aan staat gaat hij uit en andersom
    ledStatus[i] = (ledStatus[i] == LOW) ? HIGH: LOW;
    //status naar de led sturen
    digitalWrite(ledPin[i], ledStatus[i]);
  }
}
