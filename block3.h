#ifndef BLOCK3_H
#define BLOCK3_H
#include "block.h"

class Block3 : public Block
{
  public:
	Block3(Level level, BlockType type, std::shared_ptr<Score> score);
	void rotateCMappings(Point &p) override;
	void rotateCCMappings(Point &p) override;
};
#endif
