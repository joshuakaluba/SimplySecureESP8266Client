#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "Config.h"
#include "HTTPRequestHelper.h"
#include "ResponseDto.h"

HTTPRequestHelper::HTTPRequestHelper(Config &config) : config(config){};

String HTTPRequestHelper::getModuleJson(int &status)
{
  String sensorState = (status > 0) ? "1" : "0";

  String json = "{ \"ModuleId\":\"" + config.getModuleId() + "\", \"State\":" + sensorState + " }";

  return json;
}

ResponseDto HTTPRequestHelper::sendHeartbeat(int &status)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    String serverEndpoint = config.getLocalServerUrl() + heartbeatEndpoint;

    http.begin(serverEndpoint);

    http.addHeader("Content-Type", "application/json");

    int httpCode = http.POST(getModuleJson(status));

    String payload = http.getString();

    http.end();

    ResponseDto response(httpCode, payload);

    return response;
  }

  return ResponseDto(500, "An error occurred");
}

ResponseDto HTTPRequestHelper::sendModuleEvent(int &status)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    String serverEndpoint = config.getLocalServerUrl() + moduleEventEndpoint;

    http.begin(serverEndpoint);

    http.addHeader("Content-Type", "application/json");

    int httpCode = http.POST(getModuleJson(status));

    String payload = http.getString();

    http.end();

    ResponseDto response(httpCode, payload);

    return response;
  }

  return ResponseDto(500, "An error occurred");
}

ResponseDto HTTPRequestHelper::sendBootMessage(int &status)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    String serverEndpoint = config.getLocalServerUrl() + bootEventEndpoint;

    http.begin(serverEndpoint);

    http.addHeader("Content-Type", "application/json");

    int httpCode = http.POST(getModuleJson(status));

    String payload = http.getString();

    http.end();

    ResponseDto response(httpCode, payload);

    return response;
  }

  return ResponseDto(500, "An error occurred");
}

HTTPRequestHelper::~HTTPRequestHelper() {}
