void radioConfigTrans()
{
  if (!radio.begin())
  {
    Serial.println(F("radio hardware is not responding!!"));
    while (1)
    {
    }
  }
  radio.setPALevel(RF24_PA_LOW);
  radio.setPayloadSize(2);
  radio.openWritingPipe(address[1]);
  radio.openReadingPipe(1, address[0]);
  radio.stopListening();
}

bool pingRadio(bool stat)
{

 payload = (stat * 128 << 7);
 
  if (connection_ret < 16384)payload = payload | (connection_ret);
  else connection_ret = 1;
  bool report = radio.write(&payload, sizeof(float));

  if (report)
  {
    Serial.print(F("Transmission successful! "));
    Serial.print(F(" Sent: "));
    Serial.println(payload);
    connection_ret = 0;
    return true;
  }
  else
  {
    Serial.println(F("Transmission failed or timed out"));
    connection_ret += 1;
    return false;
  }
}
