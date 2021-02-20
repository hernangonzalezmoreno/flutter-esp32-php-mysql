<?php

$archivo = fopen( "datos.json", "r") or die( "No es posible abrir el archivo!" );

//leemos la primera linea del archivo
$json = fgets( $archivo );

//cerramos el archivo
fclose( $archivo );

//decodificamos el JSON
$json = json_decode( $json );

$fechaHora = new DateTime();
$fechaHora->setTimestamp( $json->tiempoUnix );

$fecha = $fechaHora->format('d-m-Y');
$hora = $fechaHora->format('H:i');

$tempDeseada = $json->tempDeseada;
$tempCava = $json->tempCava;
$voltaje = $json->estado;

/*echo $fecha.'<br />';
echo $hora.'<br />';
echo $tempDeseada.'<br />';
echo $tempCava.'<br />';
echo $voltaje.'<br />';*/

 ?>

 <header class="w3-container w3-light-gray" style="text-align:center;">
   <h6><?php echo $hora.' '.$fecha; ?></h6>
 </header>

 <div class="w3-container" style="text-align:center;">
   <p>
     Temperatura de la Cava:<br />
     <span style="font-size:x-large;"><?php echo $tempCava; ?></span><br />
     Voltaje: <?php echo $voltaje; ?>
   </p>
   <p>
     Temperatura deseada: <?php echo $tempDeseada; ?>
   </p>
 </div>
