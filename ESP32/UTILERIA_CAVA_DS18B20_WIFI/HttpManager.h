#ifndef HttpManager_h
#define HttpManager_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Const.h"
#include <WiFi.h>
#include <HTTPClient.h>

#define RUTA_TEMP_DESEADA "/temperatura_deseada.php"
#define RUTA_DATOS "/datos.php"
#define GUARDAR_DATOS "/guardar_datos.php"

class HttpManager{

  public:
    HttpManager();
    void setup();
    void reportarDatos( byte, float, String );
    void guardarDatos( byte, float, String );
    void enviarTemperaturaDeseada( byte );
    String leerTemperaturaDeseada();

  private:
    String consultarHost( String ruta );

};

#endif
