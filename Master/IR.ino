bool IRdetected() {
  average *= averageLength;
  average -= pulse[pulsePositioinCounter];
  pulse[pulsePositioinCounter] = analogRead(A0);
  average += pulse[pulsePositioinCounter];
  average /= averageLength;
  if (pulse[pulsePositioinCounter] - average >= delta) {
    //pulsePeriod = millis() - previousMillisPulse;
    previousMillisPulse = millis();
  }
  pulsePositioinCounter = (pulsePositioinCounter + 1) % averageLength;
  if (millis() - previousMillisPulse > period) {
    return true;
  }
  return false;
}
