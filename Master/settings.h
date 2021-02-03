// Radio connection
RF24 radio(7, 8); 
uint8_t address[][6] = {"Valen1","Valen2"};
float payload = 0.0;
#define TIMEOUT_BUFFER 2000
long int radio_timeout=TIMEOUT_BUFFER;
