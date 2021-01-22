#include "ComunicacionSerial.h"
#include "Controlador.h"

void ComunicacionSerial::setControlador( Controlador *pC ){
  pControlador = pC;
}

void ComunicacionSerial::leerSerial(){
  String lecturaSerial = "";

  if( Serial.available() ) lecturaSerial = Serial.readString();

  if( !lecturaSerial.equals( "" ) ){ //antes se puede preguntar por esto -> lecturaSerial != NULL || lecturaSerial.length() > 0 (abria que probar si sirve de algo)

    //Compruebo si los ultimos dos caracteres son saltos de linea, si es asi lo quito
    for( int i = 0; i < 2; i++ ){
      char caracter = lecturaSerial.charAt( lecturaSerial.length() - 1 );
      if( caracter == '\n' || caracter == '\r' ) lecturaSerial = lecturaSerial.substring( 0, lecturaSerial.length() - 1 );
    }

    procesarLectura( lecturaSerial );

  }

}

bool ComunicacionSerial::isNumeroEnteroPositivo( String lectura ){
  //Compruebo que los caracteres sean numeros
  for( int i = 0; i < lectura.length(); i++ ){
    if( !isDigit( lectura.charAt( i ) ) ) return false;
  }
  return true;
}

void ComunicacionSerial::procesarLectura( String lectura ){

  if( isNumeroEnteroPositivo( lectura ) ){
    pControlador->setTemperaturaDeseada( lectura.toInt(), true );

  }else if( lectura.equals( "Moduchip" ) ){
    Serial.println( "Utileria:" + (String) NOMBRE_SKETCH );
  }

}
