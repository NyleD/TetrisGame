#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <map>

class Interpreter
{

	std::map<std::string, std::string> cmd_map;

  public:
	std::string getCommand(std::string input);
	Interpreter(std::string inputfile);
	~Interpreter();
};

#endif
