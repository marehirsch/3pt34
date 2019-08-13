void disp() {
  lcd.clear();
  while (Serial.available() > 0) {
    // display each character to the LCD
    lcd.write(Serial.read());
  }
}
