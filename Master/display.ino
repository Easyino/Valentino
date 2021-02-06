
//for printing only numbers(fast)
void dispPrint(unsigned long int num)
{

    //blinking points every half second

    isTwoPoints = millis() % 1000 > 500;

    //displaying the number, starting from the less significant figure
    digitalWrite(DISPSET, 0);
    for (int i = 0; i < 5; i++)
    {
        shiftOut(DISPDATA, DISPCLOCK, LSBFIRST, numbers[num % 10] + isTwoPoints);
        num = num / 10;
    }
    digitalWrite(DISPSET, 1);
}

//for printing characters
void dispPrintChar(char car[5])
{

    //displaying the number, starting from the less significant figure
    digitalWrite(DISPSET, 0);
    for (int i = 0; i < 5; i++)
    {
        shiftOut(DISPDATA, DISPCLOCK, LSBFIRST, getCharacter(car[i]));
    }
    digitalWrite(DISPSET, 1);
}

byte getCharacter(char car)
{
    switch (car)
    {
    case 48 ... 58: //in case it is a number
        return numbers[car - 48];
        break;
    case '-':
        return 0x02;
        break;

    case 'E':
        return 0x9E;
        break;
    case 'R':
        return 0x0A;
        break;

    default: //print the decimal point
        return 0x01;
        break;
    }
}