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
        title: Text('CAVA'),
      ),
      
      body: Center(
        child: Column(
          mainAxisSize: MainAxisSize.max,
          mainAxisAlignment: MainAxisAlignment.center,
          children: [

            Text( 
              "${cavaApiRest.datos['tiempoUnix']}",
              style: TextStyle(
                fontSize: 25,
                /*fontWeight: FontWeight.bold,
                color: Colors.green,
                backgroundColor: Colors.pink*/
              ), 
            ),
            
            
            Text( 
              "Temp. Deseada",
              style: TextStyle(
                fontSize: 25,
              ), 
            ),

            Text( 
              "Temp. interior CAVA",
              style: TextStyle(
                fontSize: 30
              ),
            ),
            
            Text( "Estado" )


          ],
        ),
      ),

      floatingActionButton: FloatingActionButton(
        child: Icon( Icons.accessibility_new ),
        onPressed: () => cavaApiRest.actualizarDatos(),
      ),
    );

  }

}