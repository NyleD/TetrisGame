#include "block2.h"

Block2::Block2(Level level, BlockType type, std::shared_ptr<Score> score)
: Block{level, type, score} {}

void Block2::rotateCMappings(Point &p)
{

  if (p.row == 0 && p.col == 0)
  {
    p.row = 1;
    p.col = 0;
  }
  else if (p.row == 1 && p.col == 0)
  {
    p.row = 0;
    p.col = 1;
  }
  else if (p.row == 0 && p.col == 1)
  {
    p.row = 0;
    p.col = -1;
  }
  else if (p.row == 1 && p.col == 1)
  {
    p.row = -1;
    p.col = 0;
  }
}

void Block2::rotateCCMappings(Point &p)
{

  if (p.row == 0 && p.col == 0)
  {
    p.row = 0;
    p.col = 1;
  }
  else if (p.row == 1 && p.col == 0)
  {
    p.row = -1;
    p.col = 0;
  }
  else if (p.row == 0 && p.col == 1)
  {
    p.row = 1;
    p.col = 0;
  }
  else if (p.row == 1 && p.col == 1)
  {
    p.row = 0;
    p.col = -1;
  }
}
