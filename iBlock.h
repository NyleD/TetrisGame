#ifndef IBLOCK_H
#define IBLOCK_H
#include <vector>
#include <memory>
#include "block4.h"
#include "score.h"
#include "types.h"
#include "exception.h"
#include "grid.h"

class IBlock : public Block4
{
  public:
	IBlock(Level level, BlockType type, std::shared_ptr<Score> score);
	void init(std::shared_ptr<Grid> g) override;
};

#endif
