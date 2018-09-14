#ifndef JBLOCK_H
#define JBLOCK_H
#include <vector>
#include <memory>
#include "block3.h"
#include "score.h"
#include "types.h"

class JBlock : public Block3
{
  public:
	JBlock(Level level, BlockType type, std::shared_ptr<Score> score);
	void init(std::shared_ptr<Grid> g) override;
};

#endif
