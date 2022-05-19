
#include <string.h>
void setup() {
  Serial.begin(9600);
}
//PWM pulse width modulation

int ure(time_t s){
  return(s/3600)%24;
}
int minutee(time_t s){
  return(s/60)%60;
}
int sekunde(time_t s){
  return s%60;
}
void oblikujUro(char *buff, time_t s, bool sistem12,bool kaziH, bool kaziM){
  char amPm[] = "  ";
  int ure = ure(s);
  if (sistem12){
    if(ure<12)strcpy(amPm,"am");
    else strcpy(amPm,"pm");
    h = h % 12;
    if(h == 0)h=12;
  }
  
  int minutee = minutee(s);
  int sekunde = sekunde(s);
  sprintf(buff,"%2d:02d.%02d %s",ure,minutee,sekunde,amPm);
  if(!kaziH)buff[0]=buff[1] = ' ';
  if(!kaziM)buff[3]=buff[4] = ' ';
}

void loop() {
  static unsigned int marker = millis();
  static time_t sek = 1848901;
  if(millis() - marker >=1000){
    sek++;
    marker += 1000;
  }

  char buff[20];
  oblikujUro(buff, sek,true,true,true);
  printf("%s",buff);
}
