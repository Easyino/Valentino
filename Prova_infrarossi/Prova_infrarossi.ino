#include <alpha.h>
Easy scheda(true);
#define delta 1.5
#define period 35
#define averageLength 10
#define affLength 50
int pulsePeriod = 0;
int counter = 0;
int counter1 = 0;
bool passed = false;
unsigned long int previousMillisPulse;
unsigned int pulse[averageLength];
unsigned int trigg[affLength];
float average = 0;
float affidability = 0;
void setup() {
  Serial.begin(1000000);
  pinMode(A1, INPUT);
  previousMillisPulse = millis();
}

void loop() {
  Serial.print(delta);
  Serial.print(" | ");
  Serial.print(pulse[counter] - average);
  Serial.print(" | ");
  Serial.print(passed - 5);
  Serial.print(" | ");
  Serial.print(affidability / 100 - 5);
  Serial.print(" | ");
  Serial.println(- 5);
  average *= averageLength;
  average -= pulse[counter];
  pulse[counter] = analogRead(A1);
  average += pulse[counter];
  average /= averageLength;


  if (pulse[counter] - average >= delta) {
    pulsePeriod = millis() - previousMillisPulse;
    previousMillisPulse = millis();
  }

  if (millis() - previousMillisPulse > period) {
    passed = true;
  }
  else {
    passed = false;
  }

  affidability *= affLength;
  affidability -= trigg[counter1];
  trigg[counter1] = passed * 100;
  affidability += trigg[counter1];
  affidability /= affLength;

  if (affidability >= 80) {
    scheda.accendi(0, 0, 0);
  }
  else {
    scheda.accendi(255, 0, 0);
  }

  counter = (counter + 1) % averageLength;
  counter1 = (counter1 + 1) % affLength;
}
