#include "block4.h"

Block4::Block4(Level level, BlockType type, std::shared_ptr<Score> score)
: Block(level, type, score) {}

void Block4::rotateCMappings(Point &p)
{
  if (p.row == 0 && p.col == 0)
  {
    p.row = 3;
    p.col = 0;
  }
  else if (p.row == 1 && p.col == 0)
  {
    p.row = 2;
    p.col = 1;
  }
  else if (p.row == 2 && p.col == 0)
  {
    p.row = 1;
    p.col = 2;
  }
  else if (p.row == 3 && p.col == 0)
  {
    p.row = 0;
    p.col = 3;
  }
  else if (p.row == 0 && p.col == 1)
  {
    p.row = 2;
    p.col = -1;
  }
  else if (p.row == 1 && p.col == 1)
  {
    p.row = 1;
    p.col = 0;
  }
  else if (p.row == 2 && p.col == 1)
  {
    p.row = 0;
    p.col = 1;
  }
  else if (p.row == 3 && p.col == 1)
  {
    p.row = -1;
    p.col = 2;
  }
  else if (p.row == 0 && p.col == 2)
  {
    p.row = 1;
    p.col = -2;
  }
  else if (p.row == 1 && p.col == 2)
  {
    p.row = 0;
    p.col = -1;
  }
  else if (p.row == 2 && p.col == 2)
  {
    p.row = -1;
    p.col = 0;
  }
  else if (p.row == 3 && p.col == 2)
  {
    p.row = -2;
    p.col = 1;
  }
  else if (p.row == 0 && p.col == 3)
  {
    p.row = 0;
    p.col = -3;
  }
  else if (p.row == 1 && p.col == 3)
  {
    p.row = -1;
    p.col = -2;
  }
  else if (p.row == 2 && p.col == 3)
  {
    p.row = -2;
    p.col = -1;
  }
  else if (p.row == 3 && p.col == 3)
  {
    p.row = -3;
    p.col = 0;
  }
}

void Block4::rotateCCMappings(Point &p)
{
  if (p.row == 0 && p.col == 0)
  {
    p.row = 0;
    p.col = 3;
  }
  else if (p.row == 1 && p.col == 0)
  {
    p.row = -1;
    p.col = 2;
  }
  else if (p.row == 2 && p.col == 0)
  {
    p.row = -2;
    p.col = 1;
  }
  else if (p.row == 3 && p.col == 0)
  {
    p.row = -3;
    p.col = 0;
  }
  else if (p.row == 0 && p.col == 1)
  {
    p.row = 1;
    p.col = 2;
  }
  else if (p.row == 1 && p.col == 1)
  {
    p.row = 0;
    p.col = 1;
  }
  else if (p.row == 2 && p.col == 1)
  {
    p.row = -1;
    p.col = 0;
  }
  else if (p.row == 3 && p.col == 1)
  {
    p.row = -1;
    p.col = -1;
  }
  else if (p.row == 0 && p.col == 2)
  {
    p.row = 2;
    p.col = 1;
  }
  else if (p.row == 1 && p.col == 2)
  {
    p.row = 1;
    p.col = 0;
  }
  else if (p.row == 2 && p.col == 2)
  {
    p.row = 0;
    p.col = -1;
  }
  else if (p.row == 3 && p.col == 2)
  {
    p.row = -2;
    p.col = -2;
  }
  else if (p.row == 0 && p.col == 3)
  {
    p.row = 3;
    p.col = 0;
  }
  else if (p.row == 1 && p.col == 3)
  {
    p.row = 2;
    p.col = -1;
  }
  else if (p.row == 2 && p.col == 3)
  {
    p.row = 1;
    p.col = -2;
  }
  else if (p.row == 3 && p.col == 3)
  {
    p.row = 0;
    p.col = -3;
  }
}
Block4::~Block4() {}
