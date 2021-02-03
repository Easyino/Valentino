void radioConfigRec() {

  int ret = 10;
  while (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    ret--;
    delay(500);
    if (ret < 0)    while (1) {}
  }

  radio.setPALevel(RF24_PA_LOW);
  radio.setPayloadSize(sizeof(payload));
  radio.openWritingPipe(address[0]);
  radio.openReadingPipe(1, address[1]);
  radio.startListening();
  while (!getRadioMessage());
}

bool getRadioMessage() {
  uint8_t pipe;
  if (radio.available(&pipe)) {
    uint8_t bytes = radio.getPayloadSize();
    radio.read(&payload, bytes);
    Serial.println(payload);
    radio_timeout = millis() + TIMEOUT_BUFFER;
    return true;
  }
  return false;

}
