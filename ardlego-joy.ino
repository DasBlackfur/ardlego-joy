#include <legopowerfunctions.h>

byte analogX = A1;
byte analogY = A0;

int X = 0;
int Y = 0;

LEGOPowerFunctions lego(11);

int analogToLEGOPWM(int num) {
  if (num > 0 && num <= 64) {
    return 9;
  } else if (num > 64 && num <= 128) {
    return 10;
  } else if (num > 128 && num <= 192) {
    return 11;
  } else if (num > 192 && num <= 256) {
    return 12;
  } else if (num > 256 && num <= 320) {
    return 13;
  } else if (num > 320 && num <= 384) {
    return 14;
  } else if (num > 384 && num <= 448) {
    return 15;
  } else if (num > 448 && num <= 576) {
    return 8;
  } else if (num > 576 && num <= 640) {
    return 1;
  } else if (num > 640 && num <= 704) {
    return 2;
  } else if (num > 704 && num <= 768) {
    return 3;
  } else if (num > 768 && num <= 832) {
    return 4;
  } else if (num > 832 && num <= 896) {
    return 5;
  } else if (num > 896 && num <= 960) {
    return 6;
  } else if (num > 960 && num <= 1024) {
    return 7;
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  X = analogRead(analogX);
  Y = analogRead(analogY);
  Serial.print("X: ");
  Serial.print(X);
  Serial.print(" Y: ");
  Serial.print(Y);
  Serial.print(" PWMX: ");
  //Serial.print(analogToLEGOPWMBlue(X));
  Serial.print(analogToLEGOPWM(X+1));
  Serial.print(" PWMY: "); 
  //Serial.println(analogToLEGOPWMRed(Y));
  Serial.println(analogToLEGOPWM(Y+1));
  lego.ComboPWM(analogToLEGOPWM(X+1),analogToLEGOPWM(Y+1),CH1);
}
