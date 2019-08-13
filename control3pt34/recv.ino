void recv() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;

  if (Serial.available() > 0) {
    rc = Serial.read();

    //    while (Serial.available() > 0) {
    //      // display each character to the LCD
    //      lcd.write(Serial.read());
    //    }

    if (rc != endMarker) {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    }
    else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
      newData = true;
    }
  }
}

void conv() {
  if (newData == true) {
    dataNumber = 0;
    dataNumber = atoi(receivedChars);
    
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(String(motorNum));
    lcd.setCursor(0,1);
//    lcd.write(receivedChars);
    lcd.print(String(dataNumber));  
    rsg();  
    newData = false;
  }
}
