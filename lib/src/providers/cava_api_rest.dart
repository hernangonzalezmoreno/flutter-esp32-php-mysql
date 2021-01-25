import 'dart:convert';

import 'package:http/http.dart' as http;

class CavaApiRest{

  Map<String, dynamic> datos;

  Future<String> actualizarDatos() async{
    String retorno;

    try{
      
      http.Response respuesta = await http.get( "http://moduchip.com.ar/cava/datos.php" );
      
      if( respuesta.statusCode == 200 ){ // El codigo 200 significa que la peticion ser realizo exitosamente
        datos = jsonDecode( respuesta.body );
        retorno = respuesta.body;
      }else{
        retorno = "Error en la peticion, statusCode: ${respuesta.statusCode}";
      }

    }catch(e){
      retorno = "Sin conexion a internet";
    }

    return retorno;
  }

}