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

  //Guardamos en la base de datos
  include 'conexion.php'; // realizamos la conexion
  $consulta = 'INSERT INTO cava_testing( id, tiempo_unix, temperatura_deseada, temperatura_cava, voltaje )
              VALUES ( NULL, '.$datos[ tiempoUnix ].', '.intval( $datos[ tempDeseada ] ).', '.floatval( $datos[ tempCava ] ).', '.floatval( $datos[ estado ] ).' )';
  $resultado = mysqli_query( $conexion, $consulta ) or die ("Algo salio mal en la Base de Datos.");

}


?>
