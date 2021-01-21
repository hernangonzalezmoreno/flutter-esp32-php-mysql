<?php

if( isset( $_GET[ tempDeseada ] ) ){

  //Abrimos el archivo con permisos de escritura. Si el archivo no existe lo creamos
  $archivo = fopen( "temperaturaDeseada.txt", "w") or die( "No es posible abrir el archivo!" );

  //Guardamos la temperatura deseada en una linea
  fwrite( $archivo, $_GET[ tempDeseada ] );

  //Cerramos el archivo
  fclose( $archivo );

  echo $_GET[ tempDeseada ];

}else{

  //Abrimos el archivo con permisos de lectura. Si el archivo no existe lo creamos
  $archivo = fopen( "temperaturaDeseada.txt", "r") or die( "No es posible abrir el archivo!" );

  //leemos la primera linea del archivo
  echo fgets( $archivo );

  //cerramos el archivo
  fclose( $archivo );

}

?>
