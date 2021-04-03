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
bool onTimer = 0;

//display
#define DISPDATA 3
#define DISPCLOCK 4
#define DISPSET 5
#define IRSTATE A1
#define IRRECIVER A0

//numbers(0-9) in hex format.
/*

   A
F     B
   G
E     C
   D

segment value:
A  B  C  D | E  F  G  dp
8  4  2  1 | 8  4  2  1
*/

byte numbers[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};
bool isTwoPoints;

//IR
#define delta 5
#define period 35
#define averageLength 200
//int pulsePeriod = 0;
int pulsePositioinCounter = 0;
unsigned long int previousMillisPulse;
unsigned int pulse[averageLength];
float average = 0;
