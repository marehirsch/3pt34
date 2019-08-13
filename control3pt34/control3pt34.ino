#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int IN[36] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37};

boolean dir = false;
int motorNum = 0;
int steps = 0;
int step_number = 0;

const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;
int dataNumber = 0;


void setup() {
  lcd.begin(16, 2);
  for (int k = 0; k < sizeof(IN); k++) {
    pinMode(IN[k], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  //  if (millis() % 5000 == 0) {
  //    OneStep(false, 0, 1500);
  //  }

//  disp();
  recv();
  conv();
//  rsg();

}
