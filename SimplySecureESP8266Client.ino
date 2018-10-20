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
    Serial.println("Waiting for connection...");
  }

  HTTPResponseDto result = startup.sendBootMessage(magneticSensor.getGpioPinStatus());

  if (result.getStatusCode() == 200)
  {
    buzzer.acknowledgeBoot();
    Serial.println(result.getResonsePayload());
  }
  else
  {
    buzzer.soundAlarm();
    Serial.println(result.getStatusCode());
    Serial.println(result.getResonsePayload());
  }
}

void loop()
{
  delay(50);

  int status = magneticSensor.getGpioPinStatus();

  if (state != status)
  {
    Serial.println(status ? "Closed.." : "Opened..");
    
    HTTPResponseDto response = httpTransmitter.sendStatusChange(status);
    
    Serial.println(response.getResonsePayload());

    //determine if sound alarm or not

    if (!firstLoop && response.soundAlarm())
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
    Serial.println("Sending heartbeat");    
    HTTPResponseDto response = httpTransmitter.sendHeartBeat(status);
    Serial.println(response.getResonsePayload());
    
    seconds = 0;
  }

  ledLight.flash();

  firstLoop = false;
}
