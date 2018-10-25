#include <Arduino.h>
#include "Config.h"
#include "BaseComponent.h"

#ifndef MAGNETICSENSOR
#define MAGNETICSENSOR

class MagneticSensor : public BaseComponent
{
public:
  int getGpioPinState();
  void activate();
  MagneticSensor(Config &config);
  ~MagneticSensor();
};

#endif
