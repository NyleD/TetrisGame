#include "block3.h"

Block3::Block3(Level level, BlockType type, std::shared_ptr<Score> score)
: Block{level, type, score} {}

void Block3::rotateCMappings(Point &p)
{
  if (p.row == 0 && p.col == 0)
  {
    p.row = 0;
    p.col = 2;
  }
  else if (p.row == 1 && p.col == 0)
  {
    p.row = -1;
    p.col = 1;
  }
  else if (p.row == 2 && p.col == 0)
  {
    p.row = -2;
    p.col = 0;
  }
  else if (p.row == 0 && p.col == 1)
  {
    p.row = 1;
    p.col = 1;
  }
  else if (p.row == 1 && p.col == 1)
  {
    p.row = 0;
    p.col = 0;
  }
  else if (p.row == 2 && p.col == 1)
  {
    p.row = -1;
    p.col = -1;
  }
  else if (p.row == 0 && p.col == 2)
  {
    p.row = 2;
    p.col = 0;
  }
  else if (p.row == 1 && p.col == 2)
  {
    p.row = 1;
    p.col = -1;
  }
  else if (p.row == 2 && p.col == 2)
  {
    p.row = 0;
    p.col = -2;
  }
}

void Block3::rotateCCMappings(Point &p)
{
  if (p.row == 0 && p.col == 0)
  {
    p.row = 2;
    p.col = 0;
  }
  else if (p.row == 1 && p.col == 0)
  {
    p.row = 1;
    p.col = 1;
  }
  else if (p.row == 2 && p.col == 0)
  {
    p.row = 0;
    p.col = 2;
  }
  else if (p.row == 0 && p.col == 1)
  {
    p.row = 1;
    p.col = -1;
  }
  else if (p.row == 1 && p.col == 1)
  {
    p.row = 0;
    p.col = 0;
  }
  else if (p.row == 2 && p.col == 1)
  {
    p.row = -1;
    p.col = 1;
  }
  else if (p.row == 0 && p.col == 2)
  {
    p.row = 0;
    p.col = -2;
  }
  else if (p.row == 1 && p.col == 2)
  {
    p.row = -1;
    p.col = -1;
  }
  else if (p.row == 2 && p.col == 2)
  {
    p.row = -2;
    p.col = 0;
  }
}
