// Radio connection
//RF24 radio(8, 7); 

//uint8_t address[][6] = {"Valen1", "Valen2"};

//int payload =0;
int connection_ret=0;
long int next_ping;

//IR
#define delta 5
#define period 35
#define averageLength 200
//int pulsePeriod = 0;
int pulsePositioinCounter = 0;
unsigned long int previousMillisPulse;
unsigned int pulse[averageLength];
float average = 0;
