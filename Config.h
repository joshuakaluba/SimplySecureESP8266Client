#include <WString.h>
#include <Arduino.h>

#ifndef CONFIG
#define CONFIG

class Config
{
private:
  String wirelessNetworkName = "networkname";
  String wirelessNetworkPassword = "password";
  String localServerUrl = "http://192.168.2.10:18000";
  String moduleId = "4711a20e-b0ff-4461-89dc-c5479e9c5ef7";
  
  int heartBeatFrequency = 30;
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
