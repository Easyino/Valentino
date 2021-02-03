
#include <SPI.h>
#include "printf.h"
#include "RF24.h"
#include "settings.h"

void setup()
{
    Serial.begin(115200);
radioConfigTrans();

}

void loop()
{

 while(!pingRadio(1)){}

    delay(1000);

}
