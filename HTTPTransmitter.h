#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "Config.h"
#include "ResponseDto.h"

#ifndef HTTPTRANSMITTER
#define HTTPTRANSMITTER

class HTTPTransmitter
{
private:
  Config config;

public:
  ResponseDto sendHeartBeat(int &status);
  ResponseDto sendStateChange(int &status);
  HTTPTransmitter(Config &config);
  ~HTTPTransmitter();
};

#endif
