import 'package:flutter/material.dart';
import 'package:flutter_cava_simple_api_rest/src/providers/cava_api_rest.dart';
import 'package:provider/provider.dart';


class Home extends StatelessWidget {
  
  const Home( {Key key} ) : super(key: key);

  @override
  Widget build(BuildContext context) {

    final cavaApiRest = Provider.of<CavaApiRest>(context);

    return Scaffold(
      
      appBar: AppBar(
        title: Text('Cava'),
      ),
      
      body: Padding(
        
        padding: const EdgeInsets.all(20),

        child: Center(
          
          child: Column(

            mainAxisSize: MainAxisSize.max,

            children: [
              
              Expanded(
                  child: Column(
                  mainAxisSize: MainAxisSize.max,
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [

                    Text(
                      "${cavaApiRest.datos['hora']}:${cavaApiRest.datos['minuto']}\n" +
                      "${cavaApiRest.datos['dia']}/${cavaApiRest.datos['mes']}/${cavaApiRest.datos['ano']}",
                      textAlign: TextAlign.center,
                      style: TextStyle(
                        fontSize: 20,
                        /*fontWeight: FontWeight.bold,
                        color: Colors.green,
                        backgroundColor: Colors.pink*/
                      ), 
                    ),
                    
                    SizedBox( height: 20.0 ),

                    Text(
                      "Temperatura de la cava:",
                      style: TextStyle(
                        fontSize: 16
                      ),
                    ),

                    Text(
                      cavaApiRest.datos['tempCava'].toString(),
                      style: TextStyle(
                        fontSize: 35
                      ),
                    ),

                    Text(
                      "Estado: ${cavaApiRest.datos['estado']}"
                    ),

                    SizedBox( height: 20.0 ),

                    Text(
                      "Temperatura deseada: ${cavaApiRest.datos['tempDeseada']}",
                      style: TextStyle(
                        fontSize: 16
                      ),
                    ),

                  ],
                ),
              ),

              Row(
                mainAxisSize: MainAxisSize.max,
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [

                  FloatingActionButton(
                    child: Icon( Icons.remove ),
                    onPressed: () => cavaApiRest.cambiarTemperaturaDeseada( -1 ),
                  ),

                  Text(
                    cavaApiRest.temperaturaDeseada.toString(),
                    style: TextStyle(
                      fontSize: 35
                    ),
                  ),

                  FloatingActionButton(
                    child: Icon( Icons.add ),
                    onPressed: () => cavaApiRest.cambiarTemperaturaDeseada( 1 ),
                  )

                ],
              )

            ],
          ),


        ),
      ),

      /*floatingActionButton: FloatingActionButton(
        child: Icon( Icons.accessibility_new ),
        onPressed: () => cavaApiRest.actualizarDatos(),
      ),*/
    );

  }

}