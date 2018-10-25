#include "Config.h"
#include "ResponseDto.h"

#ifndef STARTUP
#define STARTUP

class Startup
{
private:
  Config config;

public:
  ResponseDto sendBootMessage(int status);
  Startup(Config &config);
  ~Startup();
};

#endif
