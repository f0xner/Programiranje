
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
//Contact bounce => debounce filter ali software delay

//Kaj je register? Register je pomnilniška lokacija. 
//Register je most preko katerega kominicira koda z fizičnim svetom,register mora biti na točno določeni lokaciji

//HD44780 -> lcd zaslon
//R/W sponka read 1/write 0
//RS register select 0 ukaz, 1 podatek
//E enable, časovno usklajanje
//D0-D7 podatkovne linije

//Časovni diagram

//Matrix keypad

int leds[] = {9,10,11,12,0};

#define TIPKA 11
void setup() {
  unsigned int ms = 200;
  unsigned int div = (unsigned int)(ms*16.384 -1);
  for(int i =0;leds[i];i++){
    pinMode(leds[i],OUTPUT);
  }
  Serial.begin(9600);
  //REG register
  //P port
  //IO input/output
  //IF filter
  //E enable
  //R register
  REG_PIOD_IFER |= 1<<7;
  
  //DEBOUNC FILTER SELECT 
  REG_PIOD_DIFSR |= 1<<7;
  
  //Slow clock divide register
  REG_PIOD_SCDR = div;

  //Naloga 11.4

  
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
