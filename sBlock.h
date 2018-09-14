#ifndef SBLOCK_H
#define SBLOCK_H
#include <vector>
#include <memory>
#include "block3.h"
#include "score.h"
#include "types.h"

class SBlock : public Block3
{
  public:
	SBlock(Level level, BlockType type, std::shared_ptr<Score> score);
	void init(std::shared_ptr<Grid> g) override;
};

#endif
