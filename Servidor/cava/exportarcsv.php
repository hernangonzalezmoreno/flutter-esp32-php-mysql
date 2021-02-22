<?php

  //fuente: https://www.virendrachandak.com/techtalk/creating-csv-file-using-php-and-mysql/

  $desde = $_GET[ desde ];
  $hasta = $_GET[ hasta ];

  //Proceso los datos para colocarle un nombre al archivo .csv
  $fechaHora_desde = new DateTime();
  $fechaHora_hasta = new DateTime();

  $fechaHora_desde->setTimestamp( $desde );
  $fechaHora_hasta->setTimestamp( $hasta );

  $nombre_archivo_csv = "registro_cava_desde_".$fechaHora_desde->format('d-m-Y_H-i')."hs_hasta_".$fechaHora_hasta->format('d-m-Y_H-i')."hs.csv";

  //encabezados de salida para que el archivo se descargue en lugar de mostrarse
  header('Content-type: text/csv');
  header('Content-Disposition: attachment; filename="'.$nombre_archivo_csv.'"');

  // do not cache the file
  header('Pragma: no-cache');
  header('Expires: 0');

  include 'conexion.php'; // realizamos la conexion

  $consulta = 'SELECT * FROM cava_testing WHERE tiempo_unix >= '.$desde.' AND tiempo_unix <= '.$hasta;
  $resultado = mysqli_query( $conexion, $consulta ) or die( "Fallo la consulta a la base de datos" );

  //Creamos un archivo para descargar ;), recordar colocar los encabezados necesarios arriba
  $file = fopen('php://output', 'w');

  //Puedo definir las columnas, pero yo no lo voy a hacer
  //fputcsv($file, array('Column 1', 'Column 2', 'Column 3', 'Column 4', 'Column 5'));

  while( $registro = mysqli_fetch_assoc( $resultado ) ){

    //Tenemos que transformar la fecha Unix
    $fechaHora = new DateTime();
    $fechaHora->setTimestamp( $registro[ tiempo_unix ] );

    //Aprovecho estos espacios, soy un HDP xD
    $registro[ id ] = $fechaHora->format('d-m-Y');
    $registro[ tiempo_unix ] = $fechaHora->format('H:i');

    fputcsv( $file, $registro );

  }

  mysqli_close( $conexion );

  fclose( $file );

?>
