#ifndef LEVEL2_H
#define LEVEL2_H

#include <map>
#include "game.h"
#include "types.h"

class Level2 : public Game
{

	std::map<BlockType, int> block_probabilities;

  public:
	Level2(bool textonly, int genseed);
	void determineNextBlock(bool change_current = true,
							std::string cmd = "") override;
};

#endif
