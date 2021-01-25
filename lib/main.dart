import 'package:flutter/material.dart';
import 'package:flutter_cava_simple_api_rest/src/providers/cava_api_rest.dart';
import 'package:flutter_cava_simple_api_rest/src/screens/home.dart';
import 'package:provider/provider.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {

  @override
  Widget build(BuildContext context) {
    
    return Provider(

      create: (_) => CavaApiRest(),

      child: MaterialApp(
        title: 'Material App',
        initialRoute: 'home',
        routes: {
          'home': (context) => Home()
        },
      ),

    );
  
  }

}
