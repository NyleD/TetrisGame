#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <cstddef>
#include "state.h"
#include "info.h"
#include "cell.h"
#include "block.h"
#include "score.h"
#include "types.h"
#include "textdisplay.h"

class TextDisplay;
template <typename InfoType, typename StateType>
class Observer;

class Grid : public std::enable_shared_from_this<Grid>
{
  std::vector<std::vector<std::shared_ptr<Cell>>> theGrid;
  std::vector<std::shared_ptr<Block>> prevBlocks;
  std::shared_ptr<Block> currentBlock = nullptr;
  BlockType nextBlock;
  std::shared_ptr<Score> score = nullptr;
  std::shared_ptr<TextDisplay> td = nullptr;

  Level currentLevel;

  int sizeRow;
  int sizeCol;
  int ctiveForceCount = 0;

  void setCellNeighbors(int row, int col, std::shared_ptr<Cell> cell);

public:
  Grid();

  // Returns the index of the next filled row
  // starting from the bottom of the Grid
  // or -1 if all rows aren't filled
  int getNextFilledRow() const;

  // Dimensions
  int getHeight();
  int getWidth();

  // Level
  Level getLevel() const;
  void setLevel(Level level);

  // Gets the Grid
  std::vector<std::vector<std::shared_ptr<Cell>>> &getGrid();

  // Clears the row at row
  void clearRow(int row);

  // Sets up the grid.  Clears old grid, if necessary.
  void init(int numRows, int numCols, Level level,
            std::shared_ptr<TextDisplay> textd);

  void createBlock(BlockType type, bool change_current);

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);

  //Transformations
  void rotateClockwise(int n);
  void rotateCounterClockwise(int n);
  void shiftLeft(int n);
  void shiftRight(int n);
  void shiftDown(int n);
  void dropBlock();
};

#endif
