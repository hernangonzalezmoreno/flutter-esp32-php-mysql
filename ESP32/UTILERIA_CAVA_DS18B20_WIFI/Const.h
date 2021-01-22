#ifndef Const_h
#define Const_h

#define NOMBRE_SKETCH             "CAVA_DS18B20_PELTIER_ONOFF"                // Nombre del sketch
#define VERSION_SKETCH            "v0.2"                                      // Version del sketch

#define RED_SSID                  "Carlos 2"                                  // Nombre de la red WiFi
#define CONTRASENA                "graciela28"                                // password de la red WiFi
#define HOST                      "http://www.moduchip.com.ar:80/cava"        // Servidor al cual conectarse

#define PELTIER_ACTIVAR_POR_ALTO  true                                        // Activar la peltir por ALTO o por BAJO

#define TIEMPO_REPORTE_SERIAL     1000                                        // Reportar valores por serial cada X tiempo
#define TIEMPO_REPORTE_HOST       3000                                        // Reportar valores por HTTP cada X tiempo

#define PIN_PELTIER               16                                          // GPIO 16, en la placa figura como RX2
#define BUS_DS18B20               25                                          // Bus DS18B20 que sensa el interior de la Cava, placa D25
#define TIEMPO_LECTURA_DS18B20    1000                                        // Tiempo entre nueva lectura

#define UMBRAL_SUPERIOR           1                                           //
#define UMBRAL_INFERIOR           1                                           //

#define TIEMPO_UMBRAL_PELTIER     3000                                        // 

#endif
