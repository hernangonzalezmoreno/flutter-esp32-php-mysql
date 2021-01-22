#ifndef HttpManager_h
#define HttpManager_h

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Const.h"
#include <WiFi.h>
#include <HTTPClient.h>

class HttpManager{

  public:
    HttpManager();
    void setup();

  private:

};

#endif
