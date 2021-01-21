#ifndef Const_h
#define Const_h

#define NOMBRE_SKETCH "CAVA_DS18B20_PELTIER_ONOFF"
#define VERSION_SKETCH "v0.2"

#define SSID "Carlos 2"
#define CONTRASENA "graciela28"
#define HOST "http://www.moduchip.com.ar/cava"

#define TIEMPO_REPORTE 1000
#define PELTIER_ACTIVAR_POR_ALTO true

#define PIN_PELTIER 16          // GPIO 16, en la placa figura como RX2
#define BUS_DS18B20 25         // Bus DS18B20 que sensa el interior de la Cava, placa D25
#define TIEMPO_LECTURA_DS18B20 1000

#define UMBRAL_SUPERIOR 1
#define UMBRAL_INFERIOR 1

#define TIEMPO_UMBRAL_PELTIER 3000

#endif
