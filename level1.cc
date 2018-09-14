#include "grid.h"
#include "level1.h"
#include "textdisplay.h"
#include <fstream>
#include <cstdlib>

Level1::Level1(bool textonly, int genseed) : Game(textonly, Level::l1)
{
	block_probabilities.emplace(BlockType::I, 2);
	block_probabilities.emplace(BlockType::J, 2);
	block_probabilities.emplace(BlockType::L, 2);
	block_probabilities.emplace(BlockType::O, 2);
	block_probabilities.emplace(BlockType::T, 2);
	block_probabilities.emplace(BlockType::S, 1);
	block_probabilities.emplace(BlockType::Z, 1);

	// initialize random seed
	srand(genseed);

	// set level in text display
	td->setLevel(1);
}

void Level1::determineNextBlock(bool change_current, std::string cmd)
{
	if (cmd != "")
	{
		g->createBlock(typeFunctions::getBlockType(cmd), change_current);
	}
	else
	{
		// get random number between 0 and sum of
		int random_selection = rand() % 12 + 1;

		for (auto i : block_probabilities)
		{
			random_selection -= i.second;
			if (random_selection <= 0)
			{
				g->createBlock(i.first, change_current);
				break;
			}
		}
	}
}
