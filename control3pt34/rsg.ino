void rsg() { 
  if (dataNumber >= 0) {
    dir = true;
  } else {
    dir = false;
  }
  steps = abs(dataNumber);
  OneStep(dir, motorNum, steps);
  delay(2);

  motorNum+=4;
  if (motorNum >= 12) {
    motorNum = 0;
  }
}
