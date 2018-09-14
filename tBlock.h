#ifndef TBLOCK_H
#define TBLOCK_H
#include <vector>
#include <memory>
#include "block3.h"
#include "score.h"
#include "types.h"

class TBlock : public Block3
{
  public:
	TBlock(Level level, BlockType type, std::shared_ptr<Score> score);
	void init(std::shared_ptr<Grid> g) override;
};

#endif
