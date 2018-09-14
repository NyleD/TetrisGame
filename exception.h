#ifndef EOGEXCEPTION_H
#define EOGEXCEPTION_H
#include <string>

class EndOfGameException
{
	std::string message;

  public:
	EndOfGameException(std::string message);
	std::string getMessage();
};

#endif
