#include <Arduino.h>
#include "PiezoBuzzer.h"
#include "BaseComponent.h"

PiezoBuzzer::PiezoBuzzer(Config &config) : BaseComponent(config){};

void PiezoBuzzer::soundAlarm()
{
    for (int i = 0; i <= config.getNumberOfTimesToBeep(); i++)
    {
        beep(config.getDurationBetweenAlarmBeeps());
    }
}

void PiezoBuzzer::acknowledgeBoot()
{
    beep(config.getDurationOfBootAcknowledgment());
}

void PiezoBuzzer::activate()
{
    pinMode(config.getBuzzerPin(), OUTPUT);

    digitalWrite(config.getBuzzerPin(), LOW);
}

PiezoBuzzer::~PiezoBuzzer() {}
