#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Ticker.h>
#include "Config.h"
#include "PiezoBuzzer.h"
#include "LEDLight.h"
#include "MagneticSensor.h"
#include "HTTPRequestHelper.h"
#include "ResponseDto.h"

int previousState = -1;
bool sendHeartbeat = false;

Config config;
PiezoBuzzer buzzer(config);
LEDLight ledLight(config);
MagneticSensor magneticSensor(config);
HTTPRequestHelper httpRequestHelper(config);

Ticker ticker;

void heartbeatHandler()
{
  sendHeartbeat = true;
}

void checkTriggered(ResponseDto &response)
{
  if (response.alarmTriggered())
  {
    buzzer.soundAlarm();
  }
  Serial.println(response.toString());
}

void setup()
{
  Serial.begin(115200);

  magneticSensor.activate();
  buzzer.activate();
  ledLight.activate();

  WiFi.begin(config.getWirelessNetworkName().c_str(), config.getWirelessNetworkPassword().c_str());

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Waiting for connection...");
  }

  ResponseDto response;

  previousState = magneticSensor.getGpioPinState();

  response = httpRequestHelper.sendBootMessage(previousState);

  if (response.isSuccessful())
  {
    buzzer.acknowledgeBoot();
  }

  ticker.attach(config.getHeartbeatFrequency(), heartbeatHandler);

  Serial.println("Booting complete");
}

void loop()
{
  delay(50);

  int currentState = magneticSensor.getGpioPinState();

  if (previousState != currentState)
  {
    Serial.println(currentState ? "Door Closed.." : "Door Opened..");

    ResponseDto response = httpRequestHelper.sendModuleEvent(currentState);

    checkTriggered(response);

    previousState = currentState;
  }

  if (sendHeartbeat == true)
  {
    ResponseDto response = httpRequestHelper.sendHeartbeat(currentState);

    checkTriggered(response);

    Serial.println("Heartbeat sent");
    sendHeartbeat = false;
  }

  ledLight.flash();
}
