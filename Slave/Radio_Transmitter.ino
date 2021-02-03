void radioConfig()
{
    if (!radio.begin())
    {
        Serial.println(F("radio hardware is not responding!!"));
        while (1)
        {
        }
    }
    radio.setPALevel(RF24_PA_LOW);
    radio.setPayloadSize(4);

    radio.openWritingPipe(address[radioNumber]);

    radio.openReadingPipe(1, address[!radioNumber]);

    radio.stopListening();
    role = true;
}
