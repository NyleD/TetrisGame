#ifndef LEVEL3_H
#define LEVEL3_H

#include <map>
#include "game.h"
#include "types.h"

class Level3 : public Game
{

	std::map<BlockType, int> block_probabilities;

  public:
	Level3(bool textonly, int genseed);
	void determineNextBlock(bool change_current = true,
							std::string cmd = "") override;
	void rotateClockwise(int n) override;
	void rotateCounterClockwise(int n) override;
	void shiftLeft(int n) override;
	void shiftRight(int n) override;
};

#endif
