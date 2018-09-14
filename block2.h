#ifndef BLOCK2_H
#define BLOCK2_H
#include "block.h"

class Block2 : public Block
{
  public:
	Block2(Level level, BlockType type, std::shared_ptr<Score> score);
	void rotateCMappings(Point &p) override;
	void rotateCCMappings(Point &p) override;
};
#endif
