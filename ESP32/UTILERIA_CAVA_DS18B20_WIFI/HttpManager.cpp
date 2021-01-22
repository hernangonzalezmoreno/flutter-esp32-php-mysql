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

void HttpManager::reportarDatos( byte tempDeseada, float tempCava, String peltier ){

  //Chequeamos la conexion WiFi
  if( WiFi.status() == WL_CONNECTED ){
   HTTPClient http;

   //Contruimos la ruta junto con las variables get
   String serverPath =
    (String) HOST + (String) RUTA_ENVIAR_DATOS
    + "tempDeseada=" + (String) tempDeseada
    + "&tempCava=" + (String) tempCava
    + "&estado=" + peltier
   ;

   // Your Domain name with URL path or IP address with path
   http.begin(serverPath.c_str());

   // Send HTTP GET request
   int httpResponseCode = http.GET();

   if (httpResponseCode>0) {
     Serial.print("HTTP Response code: ");
     Serial.println(httpResponseCode);
     String payload = http.getString();
     Serial.println(payload);
   }
   else {
     Serial.print("Error code: ");
     Serial.println(httpResponseCode);
   }
   // Free resources
   http.end();
  }
  else {
   Serial.println("WiFi Disconnected");
  }
}
