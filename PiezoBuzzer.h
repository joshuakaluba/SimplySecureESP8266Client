#include <Arduino.h>
#include "Config.h"
#include "BaseComponent.h"

#ifndef PIEZOBUZZER
#define PIEZOBUZZER

class PiezoBuzzer : public BaseComponent
{
private:
  void beep(int durationToBeep)
  {
    digitalWrite(config.getBuzzerPin(), HIGH);
    delay(durationToBeep);
    digitalWrite(config.getBuzzerPin(), LOW);
    delay(100);
  }

public:
  void activate();
  void soundAlarm();
  void acknowledgeBoot();
  PiezoBuzzer(Config &config);
  ~PiezoBuzzer();
};

#endif
