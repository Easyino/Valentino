void radioConfigRec()
{

  int ret = 10;
  while (!radio.begin())
  {
    Serial.println(F("radio hardware is not responding!!"));
    ret--;
    delay(500);
    if (ret < 0)
      while (1){}
  }

  radio.setPALevel(RF24_PA_LOW);
  radio.setPayloadSize(sizeof(payload));
  radio.openWritingPipe(address[0]);
  radio.openReadingPipe(1, address[1]);
  radio.startListening();
  while (!getRadioMessage(&slave_ir_state, &radio_ret)){}
    
}

bool getRadioMessage(bool stat, int ret)
{
  uint8_t pipe;
  if (radio.available(&pipe))
  {
    uint8_t bytes = radio.getPayloadSize();
    radio.read(&payload, bytes);
    radio_timeout = millis() + TIMEOUT_BUFFER;
    if (payload >= 16384)
    {
      endTimer(0);
      stat = true;
      ret = payload - 16384;
    }
    else
    {
      stat = false;
      ret = payload;
    }
 //logging all radio parameters
    Serial.print("Payload: ");
    Serial.print(payload);
    Serial.print(" | ");
    Serial.print(payload, BIN);
    Serial.print("   stat: ");
    Serial.print(stat);
    Serial.print("    ret: ");
    Serial.println(ret);
    return true;
  }
  return false;
}
