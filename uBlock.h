#ifndef UBLOCK_H
#define UBLOCK_H
#include <vector>
#include <memory>
#include "block2.h"
#include "score.h"
#include "types.h"

class UBlock : public Block2
{
  public:
	UBlock(Level level, BlockType type, std::shared_ptr<Score> score);
	void init(std::shared_ptr<Grid> g) override;
};

#endif
