#include "Config.h"

#ifndef STARTUP
#define STARTUP

class Startup
{
private:
  Config config;

public:
  bool sendBootMessage(int status);
  Startup(Config &config);
  ~Startup();
};

#endif
