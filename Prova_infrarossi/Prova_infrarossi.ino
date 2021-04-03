#include <alpha.h>
Easy scheda(true);
#define delta 2
#define period 35
#define averageLength 200
int pulsePeriod = 0;
int counter = 0;
bool passed = false;
unsigned long int previousMillisPulse;
unsigned int pulse[averageLength];
float average = 0;
void setup() {
  Serial.begin(1000000);
  pinMode(A1, INPUT);
  previousMillisPulse = millis();
}

void loop() {
  Serial.print(pulse[counter]);
  Serial.print(" | ");
  Serial.print(average - 5);
//  if (pulsePeriod < 60) {
//    Serial.print(" | ");
//    Serial.print(pulsePeriod);
//  }
  Serial.print(" | ");
  Serial.print(passed - 10);
  Serial.print(" | ");
  Serial.println(- 10);
  average *= averageLength;
  average -= pulse[counter];
  pulse[counter] = analogRead(A1);
  average += pulse[counter];
  average /= averageLength;
  if (pulse[counter] - average >= delta) {
    pulsePeriod = millis() - previousMillisPulse;
    previousMillisPulse = millis();
  }
  counter = (counter + 1) % averageLength;
  if (millis() - previousMillisPulse > period) {
    passed = true;
    scheda.accendi(5, 0, 0);
  }
  else {
    passed = false;
    scheda.accendi(0, 0, 0);
  }
}
