#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "Config.h"
#include "HTTPResponseDto.h"

#ifndef HTTPTRANSMITTER
#define HTTPTRANSMITTER

class HTTPTransmitter
{
private:
  Config config;

public:
  HTTPResponseDto sendHeartBeat(int &status);
  HTTPResponseDto sendStatusChange(int &status);
  HTTPTransmitter(Config &config);
  ~HTTPTransmitter();
};

#endif
