#include <Arduino.h>
#include "Config.h"
#include "LEDLight.h"
#include "BaseComponent.h"

LEDLight::LEDLight(Config &config) : BaseComponent(config){};

void LEDLight::activate()
{
    pinMode(config.getLEDPin(), OUTPUT);

    digitalWrite(config.getLEDPin(), LOW);
}

void LEDLight::flash()
{
    digitalWrite(config.getLEDPin(),lightOn? LOW : HIGH);

    lightOn = !lightOn;
}

LEDLight::~LEDLight() {}
