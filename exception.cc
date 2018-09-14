#include "exception.h"

EndOfGameException::EndOfGameException(std::string message)
	: message{message} {}

std::string EndOfGameException::getMessage()
{
	return message;
}
