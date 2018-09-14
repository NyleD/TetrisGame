#ifndef LBLOCK_H
#define LBLOCK_H
#include <vector>
#include <memory>
#include "block3.h"
#include "score.h"
#include "types.h"

class LBlock : public Block3
{
  public:
	LBlock(Level level, BlockType type, std::shared_ptr<Score> score);
	void init(std::shared_ptr<Grid> g) override;
};

#endif
