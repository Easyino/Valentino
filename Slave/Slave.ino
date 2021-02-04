
#include <SPI.h>
#include "printf.h"
#include "RF24.h"
#include "settings.h"

void setup()
{
    Serial.begin(115200);
radioConfigTrans();
pinMode(3,INPUT_PULLUP);
}

void loop()
{
if(millis()>next_ping){

 while(!pingRadio(0)){}
next_ping+=1000;
}

//detect motion
if(!digitalRead(3)){
    while(!pingRadio(1)){}
}


}
