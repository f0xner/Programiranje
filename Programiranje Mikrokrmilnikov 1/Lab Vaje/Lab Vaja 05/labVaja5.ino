#define SW 8
#define CLK 2
#define DT 3
char TEKST[100] = "";
char *k_TEKST = TEKST;

char vrniZnak(int odmik);
void vstaviZnak(char znak);

void setup() {
  pinMode(SW, INPUT_PULLUP);
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  static int CLK_val, odmik = 0, odmik_last, CLK_val_last = LOW;
  static int SW_val, SW_val_last = HIGH;
  static char znak = 'A';
  CLK_val = digitalRead(CLK);
  SW_val = digitalRead(SW);
  if(CLK_val != CLK_val_last){
    if(digitalRead(DT) != CLK_val){
      if(CLK_val == LOW){
        odmik -= 1;
      }
    }else{
      if(CLK_val == LOW){
        odmik += 1;
      }
    }
  }
  CLK_val_last = CLK_val;
  
  if(odmik != odmik_last)znak = vrniZnak(odmik);
  if(SW_val == HIGH and SW_val_last == LOW)SW_val_last = HIGH;
  if(SW_val != SW_val_last){
      vstaviZnak(znak);
      SW_val_last = SW_val;
  }
  odmik_last = odmik;
  delay(5);

}
void vstaviZnak(char znak){
  if(znak == '@'){
    k_TEKST = k_TEKST - 1;
    *k_TEKST = '_';
  }else{
    *k_TEKST = znak;
    k_TEKST = k_TEKST + 1;
  }
  Serial.print("TEKST: ");
  Serial.println(TEKST);
}
char vrniZnak(int odmik){
  static char znak='A';
  static int z_odmik=0;
  znak = znak + (odmik-z_odmik);
  if(znak<'@')znak = 'Z';
  else if(znak=='`' && (odmik-z_odmik)==-1)znak='Z';
  else if(znak>'Z' && znak<'a')znak = 'a';
  else if(znak>'z')znak='@';
  Serial.println(znak);
  z_odmik=odmik;
  return znak;
}
