// Radio connection
RF24 radio(7, 8); 

uint8_t address[][6] = {"Valen1", "Valen2"};

int payload =0;
int connection_ret=0;
long int next_ping;
