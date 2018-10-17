#include <WString.h>
#include "Config.h"

String Config::getWirelessNetworkName() const
{
    return wirelessNetworkName;
}

String Config::getWirelessNetworkPassword() const
{
    return wirelessNetworkPassword;
}

String Config::getLocalServerUrl() const
{
    return localServerUrl;
}

String Config::getModuleId() const
{
    return moduleId;
}

int Config::getHeartBeatFrequency() const
{
    return heartBeatFrequency;
}

int Config::getBuzzerPin() const
{
    return buzzerPin;
}

int Config::getLEDPin() const
{
    return ledPin;
}

int Config::getMagneticSensorPin() const
{
    return magneticSensorPin;
}

int Config::getNumberOfTimesToBeep() const
{
    return numberOfTimesToBeep;
}

int Config::getDurationBetweenAlarmBeeps() const
{
    return durationBetweenAlarmBeeps;
}

int Config::getDurationOfBootAcknowledgment() const
{
    return durationOfBootAcknowledgment;
}

Config::~Config() {}
