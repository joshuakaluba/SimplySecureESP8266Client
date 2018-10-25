#include "Startup.h"
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "Config.h"
#include "HTTPTransmitter.h"
#include "ResponseDto.h"

Startup::Startup(Config &config) : config(config){};

ResponseDto Startup::sendBootMessage(int status)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    String serverEndpoint = config.getLocalServerUrl() + "/api/boot";

    String sensorState = (status > 0) ? "1" : "0";

    String json = "{ \"ModuleId\":\"" + config.getModuleId() + "\", \"Status\":" + sensorState + " }";

    http.begin(serverEndpoint);

    http.addHeader("Content-Type", "application/json");

    int httpCode = http.POST(json);

    String payload = http.getString();

    http.end();

    ResponseDto response(httpCode, payload);

    return response;
  }

  return ResponseDto(500, "An error occurred");
}

Startup::~Startup() {}
