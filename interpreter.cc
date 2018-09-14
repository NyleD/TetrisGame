#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "interpreter.h"

Interpreter::Interpreter(std::string inputfile)
{

	std::ifstream file(inputfile); // opens the file

	if (file.is_open())
	{

		std::string cur; // current line of input file

		while (getline(file, cur))
		{ // for each line in the file

			std::istringstream ss{cur}; // stores current line

			std::string cmd;
			ss >> cmd; // get first word in line, set as the command

			std::string key; // key associated with command

			while (ss >> key)
			{
				cmd_map.emplace(key, cmd); // add command key to map
			}
		}
	}
}

Interpreter::~Interpreter() {}

std::string Interpreter::getCommand(std::string input)
{
	auto it = cmd_map.find(input);
	if (it == cmd_map.end())
		throw std::invalid_argument("Command does not exist.");

	return it->second;
}
