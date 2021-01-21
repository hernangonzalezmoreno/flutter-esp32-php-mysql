#ifndef ComunicacionSerial_h
#define ComunicacionSerial_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Const.h"

class Controlador;
class ComunicacionSerial{

  public:
    void setControlador( Controlador * );
    void leerSerial();

  private:
    Controlador *pControlador;
    bool isNumeroEnteroPositivo( String );
    void procesarLectura( String );

};

#endif
