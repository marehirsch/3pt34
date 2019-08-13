void OneStep(bool dir, int j, int stepCount) {
//void OneStep(bool dir) {  
  for (int i = 0; i < stepCount; i++) {
    if (dir) {
      switch (step_number) {
        case 0:
          digitalWrite(IN[j], HIGH);
          digitalWrite(IN[j + 1], LOW);
          digitalWrite(IN[j + 2], LOW);
          digitalWrite(IN[j + 3], LOW);
          break;
        case 1:
          digitalWrite(IN[j], LOW);
          digitalWrite(IN[j + 1], HIGH);
          digitalWrite(IN[j + 2], LOW);
          digitalWrite(IN[j + 3], LOW);
          break;
        case 2:
          digitalWrite(IN[j], LOW);
          digitalWrite(IN[j + 1], LOW);
          digitalWrite(IN[j + 2], HIGH);
          digitalWrite(IN[j + 3], LOW);
          break;
        case 3:
          digitalWrite(IN[j], LOW);
          digitalWrite(IN[j + 1], LOW);
          digitalWrite(IN[j + 2], LOW);
          digitalWrite(IN[j + 3], HIGH);
          break;
      }
    } else {
      switch (step_number) {
        case 0:
          digitalWrite(IN[j], LOW);
          digitalWrite(IN[j + 1], LOW);
          digitalWrite(IN[j + 2], LOW);
          digitalWrite(IN[j + 3], HIGH);
          break;
        case 1:
          digitalWrite(IN[j], LOW);
          digitalWrite(IN[j + 1], LOW);
          digitalWrite(IN[j + 2], HIGH);
          digitalWrite(IN[j + 3], LOW);
          break;
        case 2:
          digitalWrite(IN[j], LOW);
          digitalWrite(IN[j + 1], HIGH);
          digitalWrite(IN[j + 2], LOW);
          digitalWrite(IN[j + 3], LOW);
          break;
        case 3:
          digitalWrite(IN[j], HIGH);
          digitalWrite(IN[j + 1], LOW);
          digitalWrite(IN[j + 2], LOW);
          digitalWrite(IN[j + 3], LOW);


      }
    }    
    step_number++;
    if (step_number > 3) {
      step_number = 0;
    }
    delay(2);
  }
}
