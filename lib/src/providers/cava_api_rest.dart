import 'dart:async';
import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

class CavaApiRest with ChangeNotifier{

  Map<String, dynamic> _datos = new Map();
  int _temperaturaDeseada;
  bool _cambiandoTemperaturaDeseada;

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
    _actualizarTemperaturaDeseada();
    _autoActualizarDatos();
  }

  get datos{
    return _datos;
  }

  get temperaturaDeseada{
    return _temperaturaDeseada;
  }

  void cambiarTemperaturaDeseada( int incremento ){

    if( _cambiandoTemperaturaDeseada ) return;
    _actualizarTemperaturaDeseada( tempDeseada: ( _temperaturaDeseada + incremento ) );

  }

  _autoActualizarDatos() async{
    await _actualizarDatos();
    return Timer( Duration(seconds: 5), _autoActualizarDatos() );
  }
  
  Future<String> _actualizarDatos() async{
    String retorno;

    try{
      
      http.Response respuesta = await http.get( "http://moduchip.com.ar/cava/datos.php" );
      
      if( respuesta.statusCode == 200 ){ // El codigo 200 significa que la peticion ser realizo exitosamente
        _datos = jsonDecode( respuesta.body );
        _datos[ 'tiempoUnix' ] = DateTime.fromMillisecondsSinceEpoch( _datos[ 'tiempoUnix' ] * 1000 );
        _datos[ 'hora' ] = _datos[ 'tiempoUnix' ].hour.toString().padLeft( 2,'0' );//con padLeft le agrego un 0 a la izquierda
        _datos[ 'minuto' ] = _datos[ 'tiempoUnix' ].minute.toString().padLeft( 2,'0' );
        _datos[ 'dia' ] = _datos[ 'tiempoUnix' ].day.toString().padLeft( 2,'0' );
        _datos[ 'mes' ] = _datos[ 'tiempoUnix' ].month.toString().padLeft( 2,'0' );
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

  Future<String> _actualizarTemperaturaDeseada( {int tempDeseada} ) async{
    String retorno;
    _cambiandoTemperaturaDeseada = true;

    /* Un parametro opcional llega como null si no es usado.
    Tambien se puede usar lo siguiente para asignarle valor cuando llega null:
    tempDeseada ??= "valor que deseo";
    */

    String parametro = tempDeseada != null? "?tempDeseada=${tempDeseada}" : "";

    try{

      http.Response respuesta = await http.get( "http://moduchip.com.ar/cava/temperatura_deseada.php${parametro}" );
      
      if( respuesta.statusCode == 200 ){ // El codigo 200 significa que la peticion ser realizo exitosamente
        _temperaturaDeseada = int.parse( respuesta.body );
        retorno = respuesta.body;
      }else{
        retorno = "Error en la peticion, statusCode: ${respuesta.statusCode}";
      }

    }catch(e){
      retorno = "Sin conexion a internet";
    }

    notifyListeners();

    _cambiandoTemperaturaDeseada = false;
    return retorno;
  }

}