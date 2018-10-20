#include <Arduino.h>
#include "HTTPResponseDto.h"

HTTPResponseDto::HTTPResponseDto(int statusCode, String responsePayload) : statusCode(statusCode), responsePayload(responsePayload){};

int HTTPResponseDto::getStatusCode()
{
    return statusCode;
}

bool HTTPResponseDto::soundAlarm()
{
    return responsePayload.indexOf("true")>0;
}

String HTTPResponseDto::getResonsePayload()
{
    return responsePayload;
}

HTTPResponseDto::~HTTPResponseDto() {}
