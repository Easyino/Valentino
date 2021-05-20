bool IRdetected() {
  average *= averageLength;
  average -= pulse[counter];
  pulse[counter] = analogRead(IRRECIVER);
  average += pulse[counter];
  average /= averageLength;

  if (pulse[counter] - average >= delta) {
    pulsePeriod = millis() - previousMillisPulse;
    previousMillisPulse = millis();
  }

  if (millis() - previousMillisPulse > period) {
    passed = true;
  }
  else {
    passed = false;
  }

  affidability *= affLength;
  affidability -= trigg[counter1];
  trigg[counter1] = passed * 100;
  affidability += trigg[counter1];
  affidability /= affLength;
  counter = (counter + 1) % averageLength;
  counter1 = (counter1 + 1) % affLength;

  
  if (affidability >= 80) {
    digitalWrite(IRSTATE, 1);
    return true;
  }
  else {
    digitalWrite(IRSTATE, 0);
    return false;
  }
}
