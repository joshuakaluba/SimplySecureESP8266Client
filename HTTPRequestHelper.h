#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "Config.h"
#include "ResponseDto.h"
#include <WString.h>

#ifndef HTTPREQUESTHELPER
#define HTTPREQUESTHELPER

class HTTPRequestHelper
{
private:
  Config config;
  String heartbeatEndpoint = "/api/Heartbeat";
  String moduleEventEndpoint = "/api/ModuleEvent";
  String bootEventEndpoint = "/api/Boot";
  String getModuleJson(int &status);

public:
  ResponseDto sendHeartbeat(int &status);
  ResponseDto sendModuleEvent(int &status);
  ResponseDto sendBootMessage(int &status);

  HTTPRequestHelper(Config &config);
  ~HTTPRequestHelper();
};

#endif
