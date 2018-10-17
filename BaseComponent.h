#include "Config.h"

#ifndef BASECOMPONENT
#define BASECOMPONENT

class BaseComponent
{
protected:
  Config config;

public:
  virtual void activate() = 0;
  BaseComponent(Config &config) : config(config){};
  ~BaseComponent() {}
};

#endif
