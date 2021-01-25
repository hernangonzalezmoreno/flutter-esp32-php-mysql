import 'package:flutter/material.dart';
import 'package:flutter_cava_simple_api_rest/src/providers/cava_api_rest.dart';


class Home extends StatelessWidget {
  
  final CavaApiRest cavaApiRest;

  const Home( this.cavaApiRest, {Key key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    
    return Scaffold(
      
      appBar: AppBar(
        title: Text('CAVA'),
      ),
      
      body: Column(
        children: <Widget>[
          Text( 'texto' ),
        ]
      ),

      floatingActionButton: FloatingActionButton(
        child: Icon( Icons.accessibility_new ),
        onPressed: () => _alPresionar(),
      ),
    );

  }

  void _alPresionar() async{
    String r = await cavaApiRest.actualizarDatos();
    print( r );
  }

}