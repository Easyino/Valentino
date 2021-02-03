
#include <SPI.h>
#include "printf.h"
#include "RF24.h"
#include "settings.h"

void setup()
{
    Serial.begin(115200);
radioConfig();

}

void loop()
{
    Serial.println("transmitter");

    unsigned long start_timer = micros();                    // start the timer
    bool report = radio.write(&payload, sizeof(float));      // transmit & save the report
    unsigned long end_timer = micros();                      // end the timer

    if (report) {
      Serial.print(F("Transmission successful! "));          // payload was delivered
      Serial.print(F("Time to transmit = "));
      Serial.print(end_timer - start_timer);                 // print the timer result
      Serial.print(F(" us. Sent: "));
      Serial.println(payload);                               // print payload sent
                 payload=0;                   // increment float payload
    } else {
      Serial.println(F("Transmission failed or timed out")); // payload was not delivered
          payload += 1;   
    }

    // to make this example readable in the serial monitor
    delay(1000);  // slow transmissions down by 1 second

}
