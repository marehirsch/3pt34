//void OneStep(bool dir) {
//  if (dir) {
//    switch (step_number) {
//      case 0:
//        digitalWrite(STEPPER_PIN_1, HIGH);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, LOW);
//        break;
//      case 1:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, HIGH);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, LOW);
//        break;
//      case 2:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, HIGH);
//        digitalWrite(STEPPER_PIN_4, LOW);
//        break;
//      case 3:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, HIGH);
//        break;
//    }
//  } else {
//    switch (step_number) {
//      case 0:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, HIGH);
//        break;
//      case 1:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, HIGH);
//        digitalWrite(STEPPER_PIN_4, LOW);
//        break;
//      case 2:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, HIGH);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, LOW);
//        break;
//      case 3:
//        digitalWrite(STEPPER_PIN_1, HIGH);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, LOW);
//
//
//    }
//  }
//  step_number++;
//  if (step_number > 3) {
//    step_number = 0;
//  }
//}
