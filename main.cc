#include "game.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "interpreter.h"
#include <iostream>
#include <sstream>

using namespace std;

std::unique_ptr<Game> levelSelect(Level l, bool textonly,
									std::string blockfile, int genseed)
{
	switch (l)
	{
	case Level::l0:
		return make_unique<Level0>(textonly, blockfile);
		break;
	case Level::l1:
		return make_unique<Level1>(textonly, genseed);
		break;
	case Level::l2:
		return make_unique<Level2>(textonly, genseed);
		break;
	case Level::l3:
		return make_unique<Level3>(textonly, genseed);
		break;
	case Level::l4:
		return make_unique<Level4>(textonly, genseed);
	}
	return make_unique<Level0>(textonly, blockfile);
}

int main(int argc, char const *argv[])
{

	///////////////////CMD-LINE OPTIONS/////////////////////

	// start new game with cmd line interface
	bool textonly = false;
	int genseed = 0;
	string blockfile = "sequence.txt";
	string interpreterfile = "aliases.txt";
	Level init = Level::l0;

	// get any commands from the command line
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];

		if (arg == "-text")
		{ // text only
			textonly = true;
		}
		else if (arg == "-seed")
		{ // set random generator seed
			++i;
			genseed = stoi(argv[i]);
		}
		else if (arg == "-scriptfile")
		{ // change sequence file
			++i;
			blockfile = argv[i];
		}
		else if (arg == "-cmdfile")
		{ // change sequence file
			++i;
			interpreterfile = argv[i];
		}
		else if (arg == "-startlevel")
		{
			++i;
			switch (stoi(argv[i]))
			{
			case 0:
				init = Level::l0;
				break;
			case 1:
				init = Level::l1;
				break;
			case 2:
				init = Level::l2;
				break;
			case 3:
				init = Level::l3;
				break;
			case 4:
				init = Level::l4;
				break;
			}
		}
	}

	///////GAME CREATION AND CMD INTERPRETER SETUP///////

	// create level
	unique_ptr<Game> ng{levelSelect(init, textonly, blockfile, genseed)};

	// create interpreter
	auto i = make_unique<Interpreter>(Interpreter(interpreterfile));

	// set first block
	ng->determineNextBlock();
	ng->determineNextBlock(false);
	// display the board
	cout << *(ng);

	////////////////////MAIN GAME LOOP///////////////////
	while (true)
	{
		string s;			// holds actual user input
		int multiplier = 1; // number of times cmd should be implemented

		if (!(cin >> s))
		{
			break;
		}

		// get multiplier (if applicable)
		if (isdigit(s[0]))
		{
			multiplier = stoi(s);
		}

		// get command alias
		ostringstream function;
		int len = s.length();
		for (int i = 0; i < len; ++i)
		{
			if (isalpha(s[i]))
			{
				function << s.at(i);
			}
		}
		string key = function.str();
		string cmd;

		try
		{

			cmd = i->getCommand(key);
			cout << cmd << endl;

			if (cmd == "clockwise")
			{
				ng->rotateClockwise(multiplier);
			}
			else if (cmd == "counterclockwise")
			{
				ng->rotateCounterClockwise(multiplier);
			}
			else if (cmd == "left")
			{
				ng->shiftLeft(multiplier);
			}
			else if (cmd == "right")
			{
				ng->shiftRight(multiplier);
			}
			else if (cmd == "drop")
			{
				ng->dropBlock();
				ng->determineNextBlock();
			}

			// change next block
			else if (cmd == "J" || cmd == "I" || cmd == "O" || cmd == "T" ||
					cmd == "Z" || cmd == "S" || cmd == "L" || cmd == "U")
			{
				ng->determineNextBlock(false, cmd);
			}

			// display the board
			cout << *(ng);
		}
		catch (invalid_argument &ia)
		{
			cout << ia.what() << endl;
		}
		catch (...)
		{
			cout << "You lose!" << endl;
			break;
		}
	}
	////////////////////////////////////////////////////

	return 0;
}
