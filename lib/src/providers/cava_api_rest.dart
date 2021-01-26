import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

class CavaApiRest with ChangeNotifier{

  Map<String, dynamic> _datos = new Map();

  CavaApiRest(){
    _datos = {
      "tiempoUnix" : 100,
      "tempDeseada" : "4",
      "tempCava" : "5",
      "estado" : "2.2"
    };
  }

  get datos{
    return _datos;
  }
  
  Future<String> actualizarDatos() async{
    String retorno;

    try{
      
      http.Response respuesta = await http.get( "http://moduchip.com.ar/cava/datos.php" );
      
      if( respuesta.statusCode == 200 ){ // El codigo 200 significa que la peticion ser realizo exitosamente
        _datos = jsonDecode( respuesta.body );
        retorno = respuesta.body;
      }else{
        retorno = "Error en la peticion, statusCode: ${respuesta.statusCode}";
      }

    }catch(e){
      retorno = "Sin conexion a internet";
    }

    notifyListeners();

    return retorno;
  }

}