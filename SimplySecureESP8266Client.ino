#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "Config.h"
#include "Startup.h"
#include "PiezoBuzzer.h"
#include "LEDLight.h"
#include "MagneticSensor.h"
#include "HTTPTransmitter.h"
#include "HTTPResponseDto.h"

int state = -1;
int count = 0;
int seconds = 0;
bool firstLoop = true;

Config config;
Startup startup(config);
PiezoBuzzer buzzer(config);
LEDLight ledLight(config);
MagneticSensor magneticSensor(config);
HTTPTransmitter httpTransmitter(config);

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
    Serial.println("Waiting for connection");
  }

  bool result = startup.sendBootMessage(magneticSensor.getGpioPinStatus());

  if (result == true)
  {
    buzzer.acknowledgeBoot();
  }
  else
  {
    buzzer.soundAlarm();
  }
}

void loop()
{
  delay(50);

  int status = magneticSensor.getGpioPinStatus();

  if (state != status)
  {
    HTTPResponseDto response = httpTransmitter.sendStatusChange(status);

    Serial.println(status ? "Closed.." : "Opened..");
    Serial.println(response.getResonsePayload());

    //determine if sound alarm or not

    if (!firstLoop)
    {
      buzzer.soundAlarm();
    }
  }

  state = status;

  count++;

  if (count == 20)
  {
    count = 0;
    seconds++;
  }

  if (seconds == config.getHeartBeatFrequency())
  {
    httpTransmitter.sendHeartBeat();
    seconds = 0;
  }

  ledLight.flash();

  firstLoop = false;
}
