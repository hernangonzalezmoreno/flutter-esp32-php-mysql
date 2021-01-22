#include "HttpManager.h"

HttpManager::HttpManager(){}

void HttpManager::setup(){
  WiFi.begin( RED_SSID, CONTRASENA );
  Serial.println("Conectando a la Red");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectado a la Red WiFi, IP Address: ");
  Serial.println(WiFi.localIP());
}
