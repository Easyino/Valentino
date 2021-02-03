#include <SPI.h>
#include "printf.h"
#include "RF24.h"
#include "settings.h"





void setup() {

  Serial.begin(115200);

  radioConfigRec();

}

void loop() {
  if (radio_timeout < millis()) {
    Serial.println("Timeout");
    radioConfigRec();
  }

  if (getRadioMessage()) {
    radio_timeout =millis()+ TIMEOUT_BUFFER;
  }
  while (analogRead(A0)) {}
}
