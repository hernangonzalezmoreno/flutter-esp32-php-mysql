#include "Controlador.h"

Controlador::Controlador(){
  comunicacion.setControlador( this );
  //pNtcCava = new NTC( PIN_NTC_CAVA );
  pinMode( PIN_PELTIER, OUTPUT );
}

void Controlador::setup(){
  httpManager.setup();
}

void Controlador::ejecutar(){
  //actualizo delta
  delta.actualizar( millis() );

  //Verifico si se debo reportar por Serial
  tiempoReportarSerial += delta.get();
  if( tiempoReportarSerial >= TIEMPO_REPORTE_SERIAL ){
    tiempoReportarSerial = 0;
    reportarSerial();
  }

  //Verifico si se debo reportar por Host
  tiempoReportarHost += delta.get();
  if( tiempoReportarHost >= TIEMPO_REPORTE_HOST ){
    tiempoReportarHost = 0;
    reportarHost();
  }

  //Encendemos o apagamos la peltier segun corresponda
  controlarPeltier();

  //Verifico si hay entradas por Serial para leer
  comunicacion.leerSerial();
}

void Controlador::setTemperaturaDeseada( int valor ){
  temperaturaDeseada = (byte) constrain( valor, 0, 50 );
  Serial.println( "OK " + (String) temperaturaDeseada );
}

void Controlador::setTemperaturaCava( float valor ){
  temperaturaCava = valor;
}

void Controlador::reportarSerial(){
  Serial.println(
    (String) temperaturaDeseada +
    "\t,\t" +
    (String) temperaturaCava +
    "\t,\t" +
    (String) (digitalRead( PIN_PELTIER )*3.3f)
  );
}

void Controlador::reportarHost(){
  httpManager.reportarDatos( temperaturaDeseada, temperaturaCava, (String) (digitalRead( PIN_PELTIER )*3.3f) );
}

void Controlador::controlarPeltier(){

  if( !enfriar && temperaturaCava >= temperaturaDeseada + UMBRAL_SUPERIOR ){

    tiempoPeltier += delta.get();
    if( tiempoPeltier >= TIEMPO_UMBRAL_PELTIER ){
      tiempoPeltier = 0;
      digitalWrite( PIN_PELTIER,
        #if PELTIER_ACTIVAR_POR_ALTO
          HIGH
        #else
          LOW
        #endif
      );
      enfriar = true;
    }

  }else if( enfriar && temperaturaCava <= temperaturaDeseada - UMBRAL_INFERIOR ){

    tiempoPeltier += delta.get();
    if( tiempoPeltier >= TIEMPO_UMBRAL_PELTIER ){
      tiempoPeltier = 0;
      digitalWrite( PIN_PELTIER,
        #if PELTIER_ACTIVAR_POR_ALTO
          LOW
        #else
          HIGH
        #endif
      );
      enfriar = false;
    }

  }else{
    tiempoPeltier = 0;
  }

}
