#include "level0.h"
#include "grid.h"
#include <fstream>
#include "textdisplay.h"

#include <iostream>

Level0::Level0(bool textonly, std::string blockfile)
: Game(textonly, Level::l0), blockfile{blockfile}
{
	// open file in file stream
	std::ifstream file(blockfile);
	// read in each word from file and fill blockorder array
	if (file.is_open())
	{
		std::string cur;
		BlockType bt;
		while (file >> cur)
		{
			bt = typeFunctions::getBlockType(cur);
			blockorder.emplace_back(bt);
		}
	}
	// set level in text display
	td->setLevel(0);
}

void Level0::determineNextBlock(bool change_current, std::string cmd)
{
	if (cmd != "")
	{
		g->createBlock(typeFunctions::getBlockType(cmd), change_current);
	}
	else
	{
		// algorithm to generate blocks
		int num_in_sequence = blockorder.size();
		int index = num_blocks_created % num_in_sequence;
		g->createBlock(blockorder.at(index), change_current);
		++num_blocks_created;
	}
}
