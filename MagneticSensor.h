#include <Arduino.h>
#include "Config.h"
#include "BaseComponent.h"

#ifndef MAGNETICSENSOR
#define MAGNETICSENSOR

class MagneticSensor : public BaseComponent
{
public:
  int getGpioPinStatus();
  void activate();
  MagneticSensor(Config &config);
  ~MagneticSensor();
};

#endif
