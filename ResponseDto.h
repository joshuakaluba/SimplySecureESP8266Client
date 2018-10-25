#include <Arduino.h>
#include "Config.h"

#ifndef RESPONSEDTO
#define RESPONSEDTO

class ResponseDto
{
private:
  int statusCode = 0;
  String responsePayload = "";

public:
  int getStatusCode();
  bool alarmTriggered();
  bool isSuccessful();
  String getResonsePayload();
  ResponseDto();
  ResponseDto(int statusCode, String responsePayload);
  ~ResponseDto();
};

#endif
