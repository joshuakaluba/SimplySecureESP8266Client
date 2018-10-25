#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <Ticker.h>
#include "Config.h"
#include "Startup.h"
#include "PiezoBuzzer.h"
#include "LEDLight.h"
#include "MagneticSensor.h"
#include "HTTPTransmitter.h"
#include "ResponseDto.h"

int previousState = -1;
bool sendHeartBeat = false;

Config config;
Startup startup(config);
PiezoBuzzer buzzer(config);
LEDLight ledLight(config);
MagneticSensor magneticSensor(config);
HTTPTransmitter httpTransmitter(config);

Ticker ticker;

void heartbeatHandler()
{
  sendHeartBeat = true;
}

void checkTriggered(ResponseDto &response)
{
  if (response.alarmTriggered())
  {
    buzzer.soundAlarm();
  }
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

  while (!response.isSuccessful())
  {
    previousState = magneticSensor.getGpioPinState();

    response = startup.sendBootMessage(previousState);

    if (response.isSuccessful())
    {
      buzzer.acknowledgeBoot();
      continue;
    }

    delay(500);
    Serial.println("Waiting to boot...");
  }

  ticker.attach(config.getHeartBeatFrequency(), heartbeatHandler);

  Serial.println("Booting complete");
}

void loop()
{
  delay(50);

  int currentState = magneticSensor.getGpioPinState();

  if (previousState != currentState)
  {
    Serial.println(currentState ? "Door Closed.." : "Door Opened..");

    ResponseDto response = httpTransmitter.sendStatusChange(currentState);

    checkTriggered(response);

    previousState = currentState;
  }

  if (sendHeartBeat == true)
  {
    ResponseDto response = httpTransmitter.sendHeartBeat(currentState);

    checkTriggered(response);

    Serial.println("Heart beat sent");

    sendHeartBeat = false;
  }

  ledLight.flash();
}
