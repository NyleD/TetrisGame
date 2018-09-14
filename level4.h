#ifndef LEVEL4_H
#define LEVEL4_H

#include <map>
#include "game.h"
#include "types.h"

class Level4 : public Game
{

	std::map<BlockType, int> block_probabilities;

  public:
	Level4(bool textonly, int genseed);
	void determineNextBlock(bool change_current = true,
							std::string cmd = "") override;
	void rotateClockwise(int n) override;
	void rotateCounterClockwise(int n) override;
	void shiftLeft(int n) override;
	void shiftRight(int n) override;
};

#endif
