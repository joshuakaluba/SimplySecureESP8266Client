#include <Arduino.h>
#include "Config.h"
#include "BaseComponent.h"

#ifndef LEDLIGHT
#define LEDLIGHT

class LEDLight : public BaseComponent
{
private:
  bool lightOn = false;

public:
  void flash();
  void activate();
  LEDLight(Config &config);
  ~LEDLight();
};

#endif
