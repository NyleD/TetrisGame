#ifndef LEVEL1_H
#define LEVEL1_H

#include <map>
#include "game.h"
#include "types.h"

class Level1 : public Game
{

	std::map<BlockType, int> block_probabilities;

  public:
	Level1(bool textonly, int genseed);
	void determineNextBlock(bool change_current = true,
							std::string cmd = "") override;
};

#endif
