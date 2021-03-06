#include <SPI.h>
#include "printf.h"
#include "RF24.h"
#include "settings.h"

void setup()
{
  
  Serial.begin(115200);

  

  //radioConfigRec();
  //btn pin for test purpose
  //pinMode(11, INPUT_PULLUP);

  //display pin
  //pinMode(6, INPUT);
  pinMode(DISPDATA, OUTPUT);
  pinMode(DISPCLOCK, OUTPUT);
  pinMode(DISPSET, OUTPUT);
  pinMode(IRSTATE, OUTPUT);


  //dispPrint(81111);
  dispPrintChar("8    ");
  while(1){}
  startTimer();
}

void loop()
{

  //only for debugging purpose
  char let;
  if (Serial.available())
  {
    let = Serial.read();
    if (let == 's')
    {
      startTimer();
      Serial.println("timer Started");
    }
    else if (let == 'e')
    {
      endTimer(0);
      Serial.println("timer has been Stopped");
    }
    else if (let == 'r')
    {
      resetTimer();
      Serial.println("timer has been Resetted");
    }
  }



  if (onTimer)
  {
    Serial.print("time: ");
    Serial.println(realTime());
    dispPrint(realTime());
  }

//  if (radio_timeout < millis())
//  {
//    Serial.println("Timeout");
//    radioConfigRec();
//  }
//  if (getRadioMessage(&slave_ir_state, &radio_ret))
//  {
//    if (slave_ir_state)
//      endTimer(0);
//  }
//  IRdetected();
}
