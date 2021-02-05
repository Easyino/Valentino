void startTimer()
{
    if (!onTimer)
    {

        initial_time = millis() / 10;
        onTimer = true;
    }
}

void endTimer(int n_ret)
{
    if (onTimer)
    {

        final_time = (millis() - n_ret * TRANSMISSION_TIME) / 10;
        onTimer = false;
        saved_time = final_time - initial_time;
        Serial.println("");
        Serial.println("------------------------------------");
        Serial.print("saved_time: ");
        Serial.println(realTime());
        Serial.print("------------------------------------");
        Serial.println("");
    }
}

void resetTimer()
{
    saved_time = 0;
}

unsigned long int realTime()
{

    if (onTimer)
        return convertTime(millis() / 10 - initial_time);
    else
        return convertTime(saved_time);
}

//from millis to the actual data to print(M:SS:DD)
unsigned long int convertTime(unsigned long int time)
{
    unsigned long int res = 0;
    unsigned long int decimals, seconds, minute;
    decimals = time % 100;
    seconds = (time / 100) % 60;
    minute = time / 6000;
    Serial.print("      | ");
    Serial.print(minute);
    Serial.print(" ");
    Serial.print(seconds);
    Serial.print(" ");
    Serial.print(decimals);
    Serial.print(" |         ");
    res = decimals + seconds * 100 + minute * 10000;

    return res;
}