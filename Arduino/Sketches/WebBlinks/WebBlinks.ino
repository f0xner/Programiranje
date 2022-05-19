#include "WiFi.h"
#include "FS.h"
#include "ESPAsyncWebServer.h"

char* ssid = "RD1";
char* password = "RD-XIX-1";

AsyncWebServer server(80);

void setup(){
  
  Serial.begin(9600);
  if (!SPIFFS.begin()){
    Serial.println("Errore");
    return;
  }
  WiFi.begin(ssid,password);

  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println(WiFi.localIP());
  server.on("/test", HTTP_GET, [](AsyncWebServerRequest *request){request->send(SPIFFS,"/test.html","text/html");});
  server.on("/test.css", HTTP_GET, [](AsyncWebServerRequest *request){request->send(SPIFFS, "/test.css", "text/css");});  
  server.begin();
}
void loop(){
  
}
