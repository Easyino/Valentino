// Radio connection
RF24 radio(7, 8);
uint8_t address[][6] = {"Valen1", "Valen2"};
int payload;

#define TRANSMISSION_TIME 100
#define TIMEOUT_BUFFER 1500

long int radio_timeout = TIMEOUT_BUFFER;

int radio_ret;
bool slave_ir_state;

//timer
unsigned long int initial_time;
unsigned long int final_time;
unsigned long int saved_time;
bool onTimer=0;