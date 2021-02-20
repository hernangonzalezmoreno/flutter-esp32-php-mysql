<?php

if(
  isset( $_GET[ tempDeseada ] ) &&
  isset( $_GET[ tempCava ] ) &&
  isset( $_GET[ estado ])
){

  $datos = array(
    'tiempoUnix'  => time(),
    'tempDeseada' => $_GET[ tempDeseada ],
    'tempCava'    => $_GET[ tempCava ],
    'estado'      => $_GET[ estado ]
  );

  $json = json_encode( $datos );

  //abrimos el archivo
  $archivo = fopen( "datos.json", "w") or die( "No es posible guardar el JSON!" );
  //guardamos el json en el archivo
  fwrite( $archivo, $json );
  //cerramos el archivo
  fclose( $archivo );

  echo $json;

}else{
  //Abrimos el archivo con permisos de lectura. Si el archivo no existe lo creamos
  $archivo = fopen( "datos.json", "r") or die( "No es posible abrir el archivo!" );
  //leemos la primera linea del archivo
  echo fgets( $archivo );
  //cerramos el archivo
  fclose( $archivo );
}


?>
