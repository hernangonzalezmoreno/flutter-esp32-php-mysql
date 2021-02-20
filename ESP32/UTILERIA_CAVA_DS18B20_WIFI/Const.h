#ifndef Const_h
#define Const_h

#define NOMBRE_SKETCH             "UTILERIA_CAVA_DS18B20_WIFI"            // Nombre del sketch
#define VERSION_SKETCH            "v0.2"                                  // Version del sketch

#define RED_SSID                  "Carolina 2.4GHz"                       // Nombre de la red WiFi
#define CONTRASENA                "lavidaesunalenteja92"                  // password de la red WiFi
#define HOST                      "http://www.moduchip.com.ar:80/cava"    // Servidor al cual conectarse

#define PELTIER_ACTIVAR_POR_ALTO  true                                    // Activar la peltir por ALTO o por BAJO

#define TIEMPO_REPORTE_SERIAL     1000                                    // Reportar valores por serial cada X milisegundos
#define TIEMPO_REPORTE_HOST       3000                                    // Reportar valores al Host cada X milisegundos
#define TIEMPO_GUARDAR_HOST       600000                                  // Guardar valores en la base de datos del Host cada X milisegundos
#define TIEMPO_LEER_HOST          2800                                    // Leer valores del Host cada X milisegundos

#define PIN_PELTIER               16                                      // GPIO 16, en la placa figura como RX2
#define BUS_DS18B20               25                                      // Bus DS18B20 que sensa el interior de la Cava, placa D25
#define TIEMPO_LECTURA_DS18B20    1000                                    // Tiempo entre nueva lectura

#define UMBRAL_SUPERIOR           1                                       // Se enciende la peltier cuando la temperatura es superior o igual a: (la temp. deseada + el umbral superior)
#define UMBRAL_INFERIOR           1                                       // Se apaga la peltier cuando la temperatura es inferior o igual a: (la temp. deseada - el umbral inferior)

#define TIEMPO_UMBRAL_PELTIER     3000                                    // Para que la peltier cambie de estado, ademas de superar los umbrales de temperatura, debe superar el umbral de tiempo

#endif
