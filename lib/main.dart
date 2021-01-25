import 'package:flutter/material.dart';
import 'package:flutter_cava_simple_api_rest/src/providers/cava_api_rest.dart';
import 'package:flutter_cava_simple_api_rest/src/screens/home.dart';
 
void main() => runApp(MyApp());

CavaApiRest cavaApiRest = CavaApiRest();
 
class MyApp extends StatelessWidget {
  
  @override
  Widget build(BuildContext context) {
    
    return MaterialApp(
      title: 'Material App',
      initialRoute: 'home',
      routes: {
        'home' : (context) => Home( cavaApiRest )
      },
    );

  }

}
