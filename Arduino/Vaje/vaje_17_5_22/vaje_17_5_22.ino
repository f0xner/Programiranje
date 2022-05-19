
void setup() {
  int i;
  for(i = 13;i>=6;i--){
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);

}
unsigned char cifre7segm[] = {0xFC, 0x60, 0xDA, 0xF2};

void prikaziCifro(int cifra){
   unsigned char prikaz = cifre7segm[cifra];
   for(int i = 0;i<=7;i++){
     if(prikaz & 0x80>>i)digitalWrite(13-i,LOW);
     else digitalWrite(13-i,HIGH);
   }
}
//Tinkercad
static unsigned long cas1 = millis();
void loop() {
  static int stevec = 3;
  unsigned long cas2 = millis();
  if(cas1-cas2>=1000){
    prikaziCifro(3);
    stevec--;
    if(stevec<0)stevec = 3;
    cas1 = cas2;
  }  
}
