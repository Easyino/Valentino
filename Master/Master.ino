#include <SPI.h>
#include "printf.h"
#include "RF24.h"
#include "settings.h"



void setup() {
  Serial.begin(115200);
  radioConfigRec();
  pinMode(12,INPUT);
}



void loop() {

Serial.println(digitalRead(12));

  char let;
  if(Serial.available()){
    let=Serial.read();
    if(let=='s'){
startTimer();
    Serial.println("timer Started");
    }
    else if(let=='e'){
endTimer(0);
    Serial.println("timer Stopped");
    }
    else if(let=='r'){
resetTimer();
    Serial.println("timer Started");
    }
  }




if(!digitalRead(13)){
startTimer();
    Serial.println("timer Started");
}
//Serial.print("time: ");
//Serial.println(realTime());




  if (radio_timeout < millis()) {
    Serial.println("Timeout");
    radioConfigRec();
  }
  if (getRadioMessage(&slave_ir_state,&radio_ret)) {}


  //only for test purpose
  while (analogRead(A0)) {}
}
