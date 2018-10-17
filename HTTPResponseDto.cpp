#include <Arduino.h>
#include "HTTPResponseDto.h"

HTTPResponseDto::HTTPResponseDto(int statusCode, String responsePayload) : statusCode(statusCode), responsePayload(responsePayload){};

int HTTPResponseDto::getStatusCode()
{
    return statusCode;
}

String HTTPResponseDto::getResonsePayload()
{
    return responsePayload;
}

HTTPResponseDto::~HTTPResponseDto() {}
