#include <Arduino.h>
#include "ResponseDto.h"

ResponseDto::ResponseDto(){};

ResponseDto::ResponseDto(int statusCode, String responsePayload) : statusCode(statusCode), responsePayload(responsePayload){};

int ResponseDto::getStatusCode()
{
  return statusCode;
}

bool ResponseDto::alarmTriggered()
{
  return responsePayload.indexOf("ALARM_FLAG") > 0;
}

bool ResponseDto::isSuccessful()
{
  return getStatusCode() == 200;
}

String ResponseDto::getResonsePayload()
{
  return responsePayload;
}

ResponseDto::~ResponseDto() {}
