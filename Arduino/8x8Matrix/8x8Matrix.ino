#define DIN 8
#define CS 3
#define CLK 2
#include "LedControl.h"
LedControl lc = LedControl(DIN,CLK,CS,1);
byte e[15] = {
  B11111000,
  B10101000,
  B10001000,
  B00000000,
  B11110000,
  B00100000,
  B01000000,
  B11110000,
  B00000000,
  B11111000,
  B10101000,
  B10001000,
  B00000000,
  B11110100
};

void setup() {
  Serial.begin(9600);
  lc.shutdown(0,false);
  lc.setIntensity(0,1);
  lc.clearDisplay(0);

}
void randomGen(int *arr){
  unsigned char r;
  byte b;
  for (int i = 0;i<8;i++){
    r = random(0x100);
    b = (byte)r;
    arr[i] = b;
  }
}

void loop() {
  int arr[8];
  randomGen(arr);
  for (int i = 0;i<8;i++){
    lc.setRow(0,i,arr[i]);
    delay(80);
  }
  delay(200);
//  for(int i = 1;i<9;i++){
//    for(int j = 1;j<9;j++){
//      int of = ((i+j+i%2+j%2)%4)/2;
//      lc.setLed(0,i-1,j-1,of);
//    }
//    delay(100);
//  }
//  for(int j = 0;j<8;j++){
//    for(int i = 0;i<8;i++){
//      lc.setRow(0,i-j,e[i]);
//    }
//    delay(500);
//    lc.clearDisplay(0);
//  }
}
