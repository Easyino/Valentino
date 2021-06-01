
#include <SPI.h>
#include "printf.h"
#include "RF24.h"
#include "settings.h"


RF24 radio(8, 7); // using pin 7 for the CE pin, and pin 8 for the CSN pin

uint8_t address[][6] = {"1Node", "2Node"};
bool radioNumber = 1; // 0 uses address[0] to transmit, 1 uses address[1] to transmit
bool role = 1;  // true = TX role, false = RX role
int payload;


void setup()
{ggg
  Serial.begin(115200);
  radioConfigTrans();
  pinMode(3, INPUT_PULLUP);

}

void loop()
{
  Serial.println("qq");
  pingRadio(1);
//
//   unsigned long start_timer = micros();                    // start the timer
//    bool report = radio.write(&payload, sizeof(float));      // transmit & save the report
//    unsigned long end_timer = micros();                      // end the timer
//
//    if (report) {
//      Serial.print(F("Transmission successful! "));          // payload was delivered
//      Serial.print(F("Time to transmit = "));
//      Serial.print(end_timer - start_timer);                 // print the timer result
//      Serial.print(F(" us. Sent: "));
//      Serial.println(payload);                               // print payload sent
//      payload +=1;                                       // increment float payload
//    } else {
//      Serial.println(F("Transmission failed or timed out")); // payload was not delivered
//    }

}
