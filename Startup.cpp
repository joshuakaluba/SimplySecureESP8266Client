#include "Startup.h"

Startup::Startup(Config &config) : config(config){};

bool Startup::sendBootMessage(int status)
{
    return true;
}

Startup::~Startup() {}
