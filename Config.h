#include <WString.h>
#include <Arduino.h>

#ifndef CONFIG
#define CONFIG

class Config
{
private:
  String wirelessNetworkName = "xxxxx";
  String wirelessNetworkPassword = "xxxxx";
  String localServerUrl = "http:192.168.2.210:5000";
  String moduleId = "abcde-1231-2131-1232";
  int heartBeatFrequency = 20;
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
  int getHeartBeatFrequency() const;
  int getBuzzerPin() const;
  int getLEDPin() const;
  int getMagneticSensorPin() const;
  int getNumberOfTimesToBeep() const;
  int getDurationBetweenAlarmBeeps() const;
  int getDurationOfBootAcknowledgment() const;
  ~Config();
};

#endif
