#include <Arduino.h>
#include "Config.h"
#include "MagneticSensor.h"
#include "BaseComponent.h"

MagneticSensor::MagneticSensor(Config &config) : BaseComponent(config){};

void MagneticSensor::activate()
{
    pinMode(config.getMagneticSensorPin(), OUTPUT);
}

int MagneticSensor::getGpioPinStatus()
{
    return digitalRead(config.getMagneticSensorPin());
}

MagneticSensor::~MagneticSensor() {}
