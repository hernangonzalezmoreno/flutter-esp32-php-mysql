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

  //Contruimos la ruta junto con las variables get
  String serverPath =
   (String) HOST + (String) RUTA_DATOS
   + "?tempDeseada=" + (String) tempDeseada
   + "&tempCava=" + (String) tempCava
   + "&estado=" + peltier
  ;

  consultarHost( serverPath );

}

void HttpManager::guardarDatos( byte tempDeseada, float tempCava, String peltier ){

  //Contruimos la ruta junto con las variables get
  String serverPath =
   (String) HOST + (String) GUARDAR_DATOS
   + "?tempDeseada=" + (String) tempDeseada
   + "&tempCava=" + (String) tempCava
   + "&estado=" + peltier
  ;

  consultarHost( serverPath );

}

void HttpManager::enviarTemperaturaDeseada( byte tempDeseada ){

  //Contruimos la ruta junto con las variables get
  String serverPath =
   (String) HOST + (String) RUTA_TEMP_DESEADA
   + "?tempDeseada=" + (String) tempDeseada
  ;

  consultarHost( serverPath );

}

String HttpManager::leerTemperaturaDeseada(){
  return consultarHost( (String) HOST + (String) RUTA_TEMP_DESEADA );
}

String HttpManager::consultarHost( String ruta ){

  //Payload
  String resultado = "";

  //Chequeamos la conexion WiFi
  if( WiFi.status() == WL_CONNECTED ){
   HTTPClient http;

   // Your Domain name with URL path or IP address with path
   http.begin( ruta.c_str() );

   // Send HTTP GET request
   int httpResponseCode = http.GET();

   if (httpResponseCode>0) {
     Serial.print("HTTP Response code: ");
     Serial.println(httpResponseCode);
     resultado = http.getString();
     Serial.println( resultado );
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

  return resultado;
}
