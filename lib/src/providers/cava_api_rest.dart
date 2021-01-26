import 'dart:async';
import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

class CavaApiRest with ChangeNotifier{

  Map<String, dynamic> _datos = new Map();

  CavaApiRest(){
    _datos = {
      "tiempoUnix" : "",
      "hora" : "",
      "minuto" : "",
      "dia" : "",
      "mes" : "",
      "ano" : "",
      "tempDeseada" : "",
      "tempCava" : "",
      "estado" : ""
    };
    autoActualizar();
  }

  get datos{
    return _datos;
  }

  autoActualizar() async{
    await actualizarDatos();
    return Timer( Duration(seconds: 5), autoActualizar() );
  }
  
  Future<String> actualizarDatos() async{
    String retorno;

    try{
      
      http.Response respuesta = await http.get( "http://moduchip.com.ar/cava/datos.php" );
      
      if( respuesta.statusCode == 200 ){ // El codigo 200 significa que la peticion ser realizo exitosamente
        _datos = jsonDecode( respuesta.body );
        _datos[ 'tiempoUnix' ] = DateTime.fromMillisecondsSinceEpoch( _datos[ 'tiempoUnix' ] * 1000 );
        _datos[ 'hora' ] = _datos[ 'tiempoUnix' ].hour;
        _datos[ 'minuto' ] = _datos[ 'tiempoUnix' ].minute;
        _datos[ 'dia' ] = _datos[ 'tiempoUnix' ].day;
        _datos[ 'mes' ] = _datos[ 'tiempoUnix' ].month;
        _datos[ 'ano' ] = _datos[ 'tiempoUnix' ].year;
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