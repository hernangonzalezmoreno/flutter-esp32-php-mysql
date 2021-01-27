import 'package:flutter/material.dart';
import 'package:flutter_cava_simple_api_rest/src/providers/cava_api_rest.dart';
import 'package:flutter_cava_simple_api_rest/src/screens/home.dart';
import 'package:provider/provider.dart';

void main(){
  runApp(

    MultiProvider(
      providers: [
        ChangeNotifierProvider( create: (_) => CavaApiRest() ),
      ],
      child: const MyApp(),
    ),

  );
}

class MyApp extends StatelessWidget {

  const MyApp({Key key}) : super(key: key);
  
  @override
  Widget build(BuildContext context) {
    
    return MaterialApp(
      title: 'Cava', // titulo que figura al minimizar la app
      initialRoute: 'home',
      routes: {
        'home': (context) => Home()
      },
    );
  
  }

}
