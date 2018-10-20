#include "Config.h"
#include "HTTPResponseDto.h"

#ifndef STARTUP
#define STARTUP

class Startup
{
private:
  Config config;

public:
  HTTPResponseDto sendBootMessage(int status);
  Startup(Config &config);
  ~Startup();
};

#endif
