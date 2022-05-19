#define SW 8
#define CLK 2
#define DT 3
char ch = 'A';

void setup() {
  pinMode(SW,INPUT_PULLUP);
  pinMode(CLK,INPUT_PULLUP);
  pinMode(DT,INPUT_PULLUP);
  Serial.begin(9600);
  
}

void loop() {
  int sw,clk,dt;
  bool sprememba = false;
  //Naloga 1 - 4. lab vaja
  sw = digitalRead(SW);
  if(sw != HIGH){
    Serial.println("Pritisk gumba.");
    delay(200);
  }
  //Naloga 2 in 3 - 4. lab vaja
  clk = digitalRead(CLK);
  if(clk != HIGH){
    ch--;
    if(ch < 'A'){
      ch = 'Z';
    }
    sprememba = true;
    Serial.println("Rotacija dajalnika v Levo.");
    delay(220);
  }
  dt = digitalRead(DT);
  if(dt != HIGH){
    ch++;
    if(ch > 'Z'){
      ch = 'A';
    }
    sprememba = true;
    Serial.println("Rotacija dajalnika v Desno.");
    delay(220);
  }
  // 
  if(sprememba){
    Serial.print(ch);
    Serial.println((int)ch);
  }
  
  
}
