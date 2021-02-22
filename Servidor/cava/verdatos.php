<?php

  include 'conexion.php'; // realizamos la conexion

  $desde = $_GET[ desde ];
  $hasta = $_GET[ hasta ];

  $consulta = 'SELECT * FROM cava_testing WHERE tiempo_unix >= '.$desde.' AND tiempo_unix <= '.$hasta;
  $resultado = mysqli_query( $conexion, $consulta ) or die( "Fallo la consulta a la base de datos" );

  $cantidadDeResultados = mysqli_num_rows( $resultado );
  echo '<h4>Cantidad de resultados: ' . $cantidadDeResultados . '</h4><br />';

  ?>

  <table width="50%" style="text-align:center;">
    <tr>
      <th>Fecha</th>
      <th>Hora</th>
      <th>Temp. deseada</th>
      <th>Temp. cava</th>
      <th>Voltaje</th>
    </tr>
    <?php
      $i = 0;
      while( $registro = mysqli_fetch_array( $resultado ) ){

        $fechaHora = new DateTime();
        $fechaHora->setTimestamp( $registro[ tiempo_unix ] );

        $colorFila = $i % 2 == 0? 'style="background-color:#EEE"' : '';
        $i++;

        echo
        '<tr '.$colorFila.'>
          <td>'.$fechaHora->format('d-m-Y').'</td>
          <td>'.$fechaHora->format('H:i').'</td>
          <td>'.$registro[ temperatura_deseada ].'</td>
          <td>'.$registro[ temperatura_cava ].'</td>
          <td>'.$registro[ voltaje ].'</td>
        </tr>';
      }
    ?>

  </table>
