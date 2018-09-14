#ifndef BLOCK4_H
#define BLOCK4_H
#include "block.h"

class Block4 : public Block
{
  public:
	Block4(Level level, BlockType type, std::shared_ptr<Score> score);
	void rotateCMappings(Point &p) override;
	void rotateCCMappings(Point &p) override;
	virtual ~Block4() = 0;
};
#endif
