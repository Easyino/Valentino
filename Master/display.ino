
//for printing only numbers(fast)
void dispPrint(unsigned long int num)
{

  //blinking points every half second
  isTwoPoints = millis() % 1000 > 500;

  //displaying the number, starting from the less significant figure
  digitalWrite(DISPSET, 0);
  int j=10000;
  for (int i = 0; i < 5; i++, j/=10)
  {

Serial.print(i);
   
    Serial.println( numbers[num/j]);

    shiftOut(DISPDATA, DISPCLOCK, LSBFIRST, numbers[num/j] + isTwoPoints);
    num = num % j;
  }

  Serial.println("---------------------");
  digitalWrite(DISPSET, 1);
}


void dispPrintReverse(char car[5])
{

  //displaying the number, starting from the less significant figure
  digitalWrite(DISPSET, 0);
  for (int i = 4; i >= 0; i--)
  {
    shiftOut(DISPDATA, DISPCLOCK, LSBFIRST, getCharacter(car[i]));
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
