// Radio connection
RF24 radio(7, 8); 

uint8_t address[][6] = {"1Node", "2Node"};


bool radioNumber = 1; // 0 uses address[0] to transmit, 1 uses address[1] to transmit



bool role = false;  // true = TX role, false = RX role



float payload = 0.0;