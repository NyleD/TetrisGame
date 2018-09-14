#ifndef LEVEL0_H
#define LEVEL0_H
#include "types.h"
#include "game.h"

class Level0 : public Game
{

	std::string blockfile;
	std::vector<BlockType> blockorder;

  public:
	Level0(bool textonly, std::string blockfile);
	void determineNextBlock(bool change_current = true,
							std::string cmd = "") override;
};

#endif
