#ifndef OBLOCK_H
#define OBLOCK_H
#include <vector>
#include <memory>
#include "block2.h"
#include "score.h"
#include "types.h"

class OBlock : public Block2
{
  public:
	OBlock(Level level, BlockType type, std::shared_ptr<Score> score);
	void init(std::shared_ptr<Grid> g) override;
};

#endif
