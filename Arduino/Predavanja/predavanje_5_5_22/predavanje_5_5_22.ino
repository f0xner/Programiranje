
//GPIO genaral purpose input output
//Plavajoča sponka (High Z) deluje kot VHOD
//Napetostni vir IZHOD logična 1 HIGH
//Tokovni ponor deluje kot masa IZHOD logična 0 LOW
//Imax = 15mA
//Rdeča dioda 1,8V
//3,3V - 1,8V = 1,5V
//I = 1,5V/220ohm = 6,81mA < Imax => ledico lahko varno uporabljamo
//cyclic executive
//BCD dekoder
//tinkercad.com

//Leakage current
//Contact bounce => bounc filter ali software delay
int leds[] = {9,10,11,12,0};


void setup() {
  for(int i =0;leds[i];i++){
    pinMode(leds[i],OUTPUT);
  }
}

void loop() {
  int i;
  static int led = 0;
  for(i = 0;leds[i];i++){
    if(i==led)digitalWrite(leds[i],HIGH);
    else digitalWrite(leds[i],LOW);
  }
  delay(300);
  led = ++led % i;

}
