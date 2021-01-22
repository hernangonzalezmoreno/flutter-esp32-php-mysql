<html>
  <head>
    <meta http-equiv="refresh" content="5" />
  </head>
  <body>
    <?php
      //Abrimos el archivo con permisos de lectura. Si el archivo no existe lo creamos
      $archivo = fopen( "datos.json", "r") or die( "No es posible abrir el archivo!" );
      //leemos la primera linea del archivo
      echo fgets( $archivo );
      //cerramos el archivo
      fclose( $archivo );
    ?>
  </body>
</html>
