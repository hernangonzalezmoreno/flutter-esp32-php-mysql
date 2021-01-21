#ifndef Controlador_h
#define Controlador_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Delta.h>
#include "ComunicacionSerial.h"
#include "Const.h"

class Controlador{

  public:
    Controlador();
    void ejecutar();
    void setTemperaturaDeseada( int );
    void setTemperaturaCava( float );

  private:
    Delta delta;
    ComunicacionSerial comunicacion;
    float temperaturaCava;
    byte temperaturaDeseada = 18;
    int tiempoReportar = 0, tiempoPeltier = 0;
    bool enfriar = false;
    void reportar();
    void controlarPeltier();

};

#endif
