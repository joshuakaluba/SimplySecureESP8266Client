#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "Config.h"
#include "HTTPTransmitter.h"
#include "HTTPResponseDto.h"

HTTPTransmitter::HTTPTransmitter(Config &config) : config(config){};

HTTPResponseDto HTTPTransmitter::sendHeartBeat()
{
  HTTPResponseDto response(1, "payload");

  return response;
}

HTTPResponseDto HTTPTransmitter::sendStatusChange(int &status)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    http.begin("http:192.168.2.210:5000");

    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpCode = http.POST(status ? "message=door closed" : "message=door open");

    String payload = http.getString();

    http.end();

    HTTPResponseDto response(httpCode, payload);

    return response;
  }
}

HTTPTransmitter::~HTTPTransmitter() {}