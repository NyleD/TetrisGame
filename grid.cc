#include "grid.h"

using namespace std;

Grid::Grid() {}

int Grid::getHeight()
{
  return sizeRow;
}
int Grid::getWidth()
{
  return sizeCol;
}

void Grid::setCellNeighbors(int row, int col, std::shared_ptr<Cell> cell)
{
  shared_ptr<Cell> above;
  shared_ptr<Cell> below;
  shared_ptr<Cell> right;
  shared_ptr<Cell> left;

  if ((0 <= (row - 1) && (row - 1) < sizeRow) &&
      (0 <= col && col < sizeCol))
  {
    above = theGrid.at(row - 1).at(col);
  }

  if ((0 <= (row + 1) && (row + 1) < sizeRow) &&
      (0 <= col && col < sizeCol))
  {

    below = theGrid.at(row + 1).at(col);
  }

  if ((0 <= (row) && (row) < sizeRow) &&
      (0 <= (col + 1) && (col + 1) < sizeCol))
  {
    right = theGrid.at(row).at(col + 1);
  }

  if ((0 <= (row) && (row) < sizeRow) &&
      (0 <= (col - 1) && (col - 1) < sizeCol))
  {
    left = theGrid.at(row).at(col - 1);
  }
  cell->setCellRelationships(above, below, right, left);
}

std::vector<std::vector<std::shared_ptr<Cell>>> &Grid::getGrid()
{
  return theGrid;
}

int Grid::getNextFilledRow() const
{
  for (int i = sizeRow - 1; i >= 0; --i)
  {
    for (int j = 0; j < sizeCol; ++j)
    {
      Info info = theGrid.at(i).at(j)->getInfo();
      if (!info.occupied)
      {
        break;
      }
      if (j == sizeCol - 1)
      {
        return i;
      }
    }
  }
  return -1;
}

Level Grid::getLevel() const
{
  return currentLevel;
}

void Grid::setLevel(Level level)
{
  currentLevel = level;
}

void Grid::clearRow(int row)
{
  for (int j = 0; j < sizeCol; j++)
  {
    theGrid.at(row).at(j)->clearCell();
  }
  if (currentLevel == Level::l4)
  {
    ctiveForceCount = 0; // Reset count
  }
}

// Observers for Cell are the Cells above and below it, and TextDisplay
void Grid::init(int numRows, int numCols, Level level,
                std::shared_ptr<TextDisplay> textd)
{
  sizeRow = numRows;
  sizeCol = numCols;
  // Assign level
  setLevel(level);

  // Set up TextDisplay Class
  td = textd;

  // Set up Score
  score = std::make_shared<Score>();

  // Link score to text display
  td->setScoreObject(score);

  // Create theGrid;
  for (int i = 0; i < sizeRow; i++)
  {
    // Set Up Each Row
    theGrid.emplace_back(std::vector<std::shared_ptr<Cell>>());
    for (int j = 0; j < sizeCol; j++)
    {
      //[i][j] = Cell(i,j);
      theGrid.at(i).emplace_back(std::make_shared<Cell>(i, j));
      theGrid.at(i).at(j)->attach(td); // Set observer
    }
  }

  // Set the neighbours of each
  for (int i = 0; i < sizeRow; i++)
  {
    for (int j = 0; j < sizeCol; j++)
    {
      setCellNeighbors(i, j, theGrid.at(i).at(j));
    }
  }

  /// Tell each Cell who its neighbours are
  for (int i = 0; i < sizeRow; i++)
  { // ROW
    for (int j = 0; j < sizeCol; j++)
    { // COL
      for (int r = -1; r < 2; r++)
      { // ROW Adjusted for neighbours
        // COL does not need to be adjusted

        // Reset To Current Cell
        int i_r = i;
        int i_c = j;

        // Get Neighbours (Just Above and Below)
        i_r = i_r + r; // r should just be -1 , 1 (NOT 0)

        if (((0 <= i_r && i_r < sizeRow) && (0 <= i_c && i_c < sizeCol)) &&
            !((i_r == i) && (i_c == j)))
        {
          theGrid.at(i).at(j)->attach(theGrid.at(i_r).at(i_c));
        }
      }
    }
  }
}

void Grid::createBlock(BlockType type, bool change_current)
{
  // Set next block
  if (!change_current)
  {
    nextBlock = type;
  }
  else
  {
    if (currentBlock)
    {
      prevBlocks.emplace_back(currentBlock);
    }
    currentBlock = Block::makeBlock(currentLevel, nextBlock,
                                  score, shared_from_this());
    nextBlock = type;
  }
}

// Transformations
void Grid::rotateClockwise(int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (!currentBlock->rotateClockwise(shared_from_this()))
    {
      break;
    }
  }
}

void Grid::rotateCounterClockwise(int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (!currentBlock->rotateCounterClockwise(shared_from_this()))
    {
      break;
    }
  }
}

void Grid::shiftLeft(int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (!currentBlock->shiftLeft())
    {
      break;
    }
  }
}

void Grid::shiftRight(int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (!currentBlock->shiftRight())
    {
      break;
    }
  }
}

void Grid::shiftDown(int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (!currentBlock->shiftDown())
    {
      break;
    }
  }
}

void Grid::dropBlock()
{
  shiftDown(sizeRow); // shifting down safely
  if (currentLevel == Level::l4)
  {
    ++ctiveForceCount;
  }
  int filledRowsCount = 0;

  while (true)
  {
    int filledRow = getNextFilledRow();
    if (filledRow != -1)
    {
      clearRow(filledRow);
      ++filledRowsCount;
    }
    else
    {
      break;
    }
  }

  // Update score
  if (filledRowsCount > 0)
  {
    score->updateCurrentScore(currentLevel, filledRowsCount);
  }
  else if (currentLevel == Level::l4 && ctiveForceCount >= 5)
  {
    ctiveForceCount = 0; // Reset count
    currentBlock = Block::makeBlock(currentLevel, BlockType::U,
                                    score, shared_from_this());
    dropBlock();
    ctiveForceCount = 0; // Reset count again to undo any changes
  }
}
