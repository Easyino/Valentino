#include <SPI.h>
#include "printf.h"
#include "RF24.h"
#include "settings.h"



void setup() {
  Serial.begin(115200);
  radioConfigRec();
  pinMode(3,INPUT_PULLUP);
}



void loop() {


  char let;
  if(Serial.available()){
    let=Serial.read();
    if(let=='s'){
startTimer();
    Serial.println("timer Started");
    }
    else if(let=='e'){
endTimer(0);
    Serial.println("timer has been Stopped");
    }
    else if(let=='r'){
resetTimer();
    Serial.println("timer has been Resetted");
    }
  }




if(!digitalRead(3)){
startTimer();
    Serial.println("timer Started");
}
if(onTimer){

Serial.print("time: ");
Serial.println(realTime());
}




  if (radio_timeout < millis()) {
    Serial.println("Timeout");
    radioConfigRec();
  }
  if (getRadioMessage(&slave_ir_state,&radio_ret)) {}
  if(slave_ir_state)endTimer(0);


  //only for test purpose
  while (analogRead(A0)) {}
}
