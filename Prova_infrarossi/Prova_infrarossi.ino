#include <alpha.h>
Easy scheda(true);
#define delta 5
#define period 50
#define averageLength 100
int counter = 0;
bool passed = false;
unsigned long int previousMillisPulse;
unsigned int pulse[averageLength];
float average = 0;
int i;
void setup() {
  Serial.begin(500000);
  pinMode(A1, INPUT);
  previousMillisPulse = millis();
}

void loop() {
  Serial.print(pulse[counter]);
  Serial.print(" | ");
  Serial.print(average - 5);
  Serial.print(" | ");
  Serial.print(passed - 10);
  Serial.print(" | ");
  Serial.println(- 10);
  average *= averageLength;
  average -= pulse[counter];
  pulse[counter] = analogRead(A1);
  average += pulse[counter];
  average /= averageLength;
  if (pulse[counter] - average >= delta){
    previousMillisPulse = millis();
  }
  counter = (counter + 1) % averageLength;
  if (millis() - previousMillisPulse > period){
    passed = true;
    scheda.accendi(5, 0, 0);
  }
  else {
    passed = false;
    scheda.accendi(0, 0, 0);
  }
}
