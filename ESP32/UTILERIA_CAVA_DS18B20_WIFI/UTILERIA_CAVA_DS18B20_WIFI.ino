/*******************************************************
* Moduchip
* Microcontrolador ESP32. Placa: DOIT ESP32 DEVKIT V1.
********************************************************/

#include <WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DS18B20Events.h>
#include "Controlador.h"
#include "Const.h"

OneWire oneWire( BUS_DS18B20 );
DallasTemperature busSensorCava( &oneWire );
DS18B20Events sensorCavaDS18B20( 0 );
Controlador controlador;

void setup(){
  Serial.begin( 115200 );
  DS18B20Events::setup( &busSensorCava );
	DS18B20Events::setInterval( TIEMPO_LECTURA_DS18B20 );
  sensorCavaDS18B20.onChange = cambioDeTemperatura;
  Serial.println( (String) NOMBRE_SKETCH + " " + (String) VERSION_SKETCH );

  Serial.println( "Conectando a la red: " + (String) SSID );
  WiFi.begin( SSID, CONTRASENA );
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }

  Serial.println( "Conexion exitosa" );
  Serial.println( "IP address: " + (String) WiFi.localIP() );

}

void loop(){
  sensorCavaDS18B20.loop();
  controlador.ejecutar();
}

void cambioDeTemperatura(uint8_t index, float tempC) {
	/*Serial.print(tempC);
	Serial.print(" nueva tempC en index ");
	Serial.println(index);*/
  controlador.setTemperaturaCava( tempC );
}

/*//en la ESP32 no esta funcionando el evento
void serialEvent(){
  controlador.comunicacion.leerSerial();
}*/
