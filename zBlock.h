#ifndef ZBLOCK_H
#define ZBLOCK_H
#include <vector>
#include <memory>
#include "block3.h"
#include "score.h"
#include "types.h"

class ZBlock : public Block3
{
  public:
	ZBlock(Level level, BlockType type, std::shared_ptr<Score> score);
	void init(std::shared_ptr<Grid> g) override;
};

#endif
