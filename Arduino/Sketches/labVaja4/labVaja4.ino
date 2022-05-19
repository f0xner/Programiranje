#define SW 8
#define CLK 2
#define DT 3
void setup() {
  pinMode(SW,INPUT_PULLUP);
  pinMode(CLK,INPUT_PULLUP);
  pinMode(DT,INPUT_PULLUP);
  Serial.begin(9600); 
}
void loop() {
  int sw,clk,dt;
  //Naloga 1 - 4. lab vaja
  sw = digitalRead(SW);
  if(sw != HIGH){
    Serial.println("Pritisk gumba.");
    delay(200);
  }
  //Naloga 2 in 3 - 4. lab vaja
  clk = digitalRead(CLK);
  if(clk != HIGH && digitalRead(DT)==HIGH){
    Serial.println("Rotacija dajalnika v Desno.");
    delay(1);
  }
  dt = digitalRead(DT);
  if(dt != HIGH&&digitalRead(CLK)==HIGH){
    Serial.println("Rotacija dajalnika v Levo.");
    delay(1);
  }
  
  
}
