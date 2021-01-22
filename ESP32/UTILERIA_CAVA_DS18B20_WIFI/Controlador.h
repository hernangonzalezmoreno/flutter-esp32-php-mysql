#ifndef Controlador_h
#define Controlador_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Delta.h>
#include "HttpManager.h"
#include "ComunicacionSerial.h"
#include "Const.h"

class Controlador{

  public:
    Controlador();
    void setup();
    void ejecutar();
    void setTemperaturaDeseada( int );
    void setTemperaturaCava( float );

  private:
    Delta delta;
    ComunicacionSerial comunicacion;
    HttpManager httpManager;
    float temperaturaCava;
    byte temperaturaDeseada = 18;
    int tiempoReportar = 0, tiempoPeltier = 0;
    bool enfriar = false;
    void reportar();
    void controlarPeltier();

};

#endif
