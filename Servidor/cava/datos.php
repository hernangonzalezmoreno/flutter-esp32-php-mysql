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

  //Guardamos en la base de datos
  include 'conexion.php'; // realizamos la conexion
  $consulta = 'INSERT INTO cava_testing( id, tiempo_unix, temperatura_deseada, temperatura_cava, voltaje )
              VALUES ( NULL, '.$datos[ tiempoUnix ].', '.intval( $datos[ tempDeseada ] ).', '.floatval( $datos[ tempCava ] ).', '.floatval( $datos[ estado ] ).' )';
  $resultado = mysqli_query( $conexion, $consulta ) or die ("Algo salio mal en la Base de Datos.");

}else{
  //Abrimos el archivo con permisos de lectura. Si el archivo no existe lo creamos
  $archivo = fopen( "datos.json", "r") or die( "No es posible abrir el archivo!" );
  //leemos la primera linea del archivo
  echo fgets( $archivo );
  //cerramos el archivo
  fclose( $archivo );
}


?>
