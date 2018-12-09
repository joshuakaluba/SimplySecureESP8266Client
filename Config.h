#include <WString.h>
#include <Arduino.h>

#ifndef CONFIG
#define CONFIG

class Config
{
private:
  String wirelessNetworkName = "xxxxx";
  String wirelessNetworkPassword = "xxxxx";
  String localServerUrl = "http://192.168.2.10:18000";
  String moduleId = "89568b1c-1cdb-44c3-8676-3a077723e1cb";

  int heartbeatFrequency = 35;
  int buzzerPin = 12;
  int ledPin = 4;
  int magneticSensorPin = 2;
  int numberOfTimesToBeep = 10;
  int durationBetweenAlarmBeeps = 100;
  int durationOfBootAcknowledgment = 1000;

public:
  String getWirelessNetworkName() const;
  String getWirelessNetworkPassword() const;
  String getLocalServerUrl() const;
  String getModuleId() const;
  int getHeartbeatFrequency() const;
  int getBuzzerPin() const;
  int getLEDPin() const;
  int getMagneticSensorPin() const;
  int getNumberOfTimesToBeep() const;
  int getDurationBetweenAlarmBeeps() const;
  int getDurationOfBootAcknowledgment() const;
  ~Config();
};

#endif
