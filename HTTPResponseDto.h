#include <Arduino.h>
#include "Config.h"

#ifndef HTTPRESPONSEDTO
#define HTTPRESPONSEDTO

class HTTPResponseDto
{
private:
  int statusCode = 0;
  String responsePayload;

public:
  int getStatusCode();
  String getResonsePayload();
  HTTPResponseDto(int statusCode, String responsePayload);
  ~HTTPResponseDto();
};

#endif
