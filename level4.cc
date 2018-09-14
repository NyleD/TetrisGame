#include "grid.h"
#include "level4.h"
#include "textdisplay.h"
#include <fstream>
#include <cstdlib>

Level4::Level4(bool textonly, int genseed) : Game(textonly, Level::l4)
{
	block_probabilities.emplace(BlockType::I, 1);
	block_probabilities.emplace(BlockType::J, 1);
	block_probabilities.emplace(BlockType::L, 1);
	block_probabilities.emplace(BlockType::O, 1);
	block_probabilities.emplace(BlockType::T, 1);
	block_probabilities.emplace(BlockType::S, 2);
	block_probabilities.emplace(BlockType::Z, 2);

	// initialize random seed
	srand(genseed);

	// set level in text display
	td->setLevel(4);
}

void Level4::determineNextBlock(bool change_current, std::string cmd)
{
	if (cmd != "")
	{
		g->createBlock(typeFunctions::getBlockType(cmd), change_current);
	}
	else
	{
		// get random number between 0 and sum of
		int random_selection = rand() % 6 + 1;

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

void Level4::rotateClockwise(int n)
{
	g->rotateClockwise(n);
	g->shiftDown(n);
}

void Level4::rotateCounterClockwise(int n)
{
	g->rotateCounterClockwise(n);
	g->shiftDown(n);
}

void Level4::shiftLeft(int n)
{
	g->shiftLeft(n);
	g->shiftDown(n);
}

void Level4::shiftRight(int n)
{
	g->shiftRight(n);
	g->shiftDown(n);
}
