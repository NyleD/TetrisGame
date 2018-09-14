#include "block.h"
#include "cell.h"
#include "grid.h"
#include "iBlock.h"
#include "jBlock.h"
#include "lBlock.h"
#include "oBlock.h"
#include "sBlock.h"
#include "zBlock.h"
#include "tBlock.h"
#include "uBlock.h"
#include "exception.h"

using namespace std;

Block::Block(Level level, BlockType type, std::shared_ptr<Score> score)
    : score{score}, level{level}, type{type}, topLeftPoint{0, 3} {}

Block::~Block() {}

void Block::initCells()
{
  for (auto &cell : cells)
  {
    // Check if another block occupies the cell
    if (cell->getIsOccupied())
    {
      throw EndOfGameException("There is not enough room on the grid to fit the next block.");
    }
    // Occupy the cell with the current block
    cell->setType(type);
    cell->setIsOccupied(true);
  }
}

void Block::notify(Subject<Info, State> &whoNotified)
{
  // Dynamic cast so we can call cell functions
  std::shared_ptr<Cell> this_cell(dynamic_cast<Cell *>(&whoNotified));

  StateType state = whoNotified.getState().type;
  Info info = whoNotified.getInfo();
  int row = info.row;
  int col = info.col;

  if (state == StateType::Clear)
  {
    for (auto &cell : cells)
    {
      Info infoCell = cell->getInfo();
      if (row == infoCell.row && col == infoCell.col)
      {
        cell = nullptr;

        // Check if the whole Block Has Been Cleared
        bool updateScore = true;
        for (auto &cell : cells)
        {
          if (cell)
          {                      // cell is not a null_ptr
            updateScore = false; // Block Has not been cleared yet
            break;
          }
        }

        if (updateScore)
        {
          score->updateCurrentScore(level);
        }
        break;
      }
    }
  }
  else if (state == StateType::MoveDown)
  {
    for (auto &cell : cells)
    {
      Info infoCell = cell->getInfo();
      if (row == infoCell.row && col == infoCell.col)
      {
        cell = this_cell->getCellBelow();
        break;
      }
    }
  }
}

bool Block::myCell(int checkRow, int checkCol)
{
  for (auto &cell : cells)
  { // Is the occupied cell in this Block?
    if ((checkRow == cell->getInfo().row) &&
        (checkCol == cell->getInfo().col))
    {
      return true;
    }
  }
  return false;
}

bool Block::rotateCell(std::shared_ptr<Cell> cell, std::string direction,
                       std::vector<std::vector<std::shared_ptr<Cell>>> &theGrid,
                       int gridHeight, int gridWidth)
{

  auto tempCell = std::make_shared<Cell>(*cell);
  Info info = cell->getInfo();
  int row = info.row - topLeftPoint.row;
  int col = info.col - topLeftPoint.col;
  struct Point rotateC
  {
    col, row
  };

  // Get new destination of Cell which way to rotate
  if (direction == "C")
  {
    rotateCMappings(rotateC);
  }
  else if (direction == "CC")
  {
    rotateCCMappings(rotateC);
  }

  int newRow = info.row + rotateC.row;
  int newCol = info.col + rotateC.col;

  if ((0 <= newCol && newCol < gridWidth) &&
      (0 <= newRow && newRow < gridHeight))
  { // Within Boundary

    if (theGrid.at(newRow).at(newCol)->getIsOccupied())
    {
      if (!myCell(newRow, newCol))
      {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool Block::rotateClockwise(std::shared_ptr<Grid> g)
{

  auto theGrid = g->getGrid();

  for (auto &cell : cells)
  {

    if (!rotateCell(cell, "C", theGrid, g->getHeight(), g->getWidth()))
    {
      return false;
    }
  }

  for (auto &cell : cells)
  {
    cell->setType(BlockType::NoType);
    cell->setIsOccupied(false);
  }

  for (auto &cell : cells)
  {
    int row = cell->getInfo().row - topLeftPoint.row;
    int col = cell->getInfo().col - topLeftPoint.col;
    struct Point rotateC
    {
      col, row
    };

    rotateCMappings(rotateC);
    int newRow = cell->getInfo().row + rotateC.row;
    int newCol = cell->getInfo().col + rotateC.col;
    cell = theGrid.at(newRow).at(newCol);
    cell->setType(type);
    cell->setIsOccupied(true);
  }
}

bool Block::rotateCounterClockwise(std::shared_ptr<Grid> g)
{

  auto theGrid = g->getGrid();

  for (auto &cell : cells)
  {

    if (!rotateCell(cell, "CC", theGrid, g->getHeight(), g->getWidth()))
    {
      return false;
    }
  }

  for (auto &cell : cells)
  {
    cell->setType(BlockType::NoType);
    cell->setIsOccupied(false);
  }

  for (auto &cell : cells)
  {
    int row = cell->getInfo().row - topLeftPoint.row;
    int col = cell->getInfo().col - topLeftPoint.col;
    struct Point rotateC
    {
      col, row
    };

    rotateCCMappings(rotateC);
    int newRow = cell->getInfo().row + rotateC.row;
    int newCol = cell->getInfo().col + rotateC.col;
    cell = theGrid.at(newRow).at(newCol);
    cell->setType(type);
    cell->setIsOccupied(true);
  }
  return true;
}

// Each shift updates topLeftPoint

bool Block::shiftLeft()
{
  // Checking if we can shift
  for (auto &cell : cells)
  { // Iterating through through each cell

    if (cell->getCellLeft())
    { // Is there a Cell to its Left?

      if (cell->getCellLeft()->getIsOccupied())
      { // Is the left Cell Occupied?
        int checkRow = cell->getCellLeft()->getInfo().row;
        int checkCol = cell->getCellLeft()->getInfo().col;

        if (!myCell(checkRow, checkCol))
        {
          return false; // does not belong to the same block -> can't shift
        }
      }
    }
    else
    { // No cell to its left
      return false;
    }
  }

  for (auto &cell : cells)
  {
    cell->setType(BlockType::NoType);
    cell->setIsOccupied(false); // Set Current Cell to false
  }

  for (auto &cell : cells)
  {
    cell = cell->getCellLeft();
    cell->setType(type);
    cell->setIsOccupied(true);
  }
  topLeftPoint.col -= 1;
  return true;
}

bool Block::shiftRight()
{

  // Checking if we can shift
  for (auto &cell : cells)
  { // Iterate Through All Cells

    if (cell->getCellRight())
    { // Is there a Cell Right
      if (cell->getCellRight()->getIsOccupied())
      { // Is Right Cell Full
        int checkRow = cell->getCellRight()->getInfo().row;
        int checkCol = cell->getCellRight()->getInfo().col;

        if (!myCell(checkRow, checkCol) &&
            cell->getCellRight()->getIsOccupied() == true)
        {
          return false; // does not belong to the same block -> can't shift
        }
      }
    }
    else
    { // No Cell Right
      return false;
    }
  }

  for (auto &cell : cells)
  {
    cell->setType(BlockType::NoType);
    cell->setIsOccupied(false); // Set Current Cell to false
  }

  for (auto &cell : cells)
  {
    cell = cell->getCellRight();
    cell->setType(type);
    cell->setIsOccupied(true);
  }

  topLeftPoint.col += 1;
  return true;
}

bool Block::shiftDown()
{
  // Check if it's Nieghbor's Cell is full
  // Can Shift ->> Got Ahead and Shift
  bool canShift = true;
  // Checking if we can shift
  for (auto &cell : cells)
  { // Iterate Through All Cells
    if (cell->getCellBelow())
    { // Is there a Cell Below
      if (cell->getCellBelow()->getIsOccupied())
      { // Is Below Cell Full
        if (!myCell(cell->getCellBelow()->getInfo().row,
                    cell->getCellBelow()->getInfo().col))
        {
          canShift = false;
          break;
        }
      }
    }
    else
    {
      canShift = false;
    }
  }

  if (canShift)
  { // If we can shift
    for (auto &cell : cells)
    {
      cell->setType(BlockType::NoType);
      cell->setIsOccupied(false); // Set Current Cell to false
    }

    for (auto &cell : cells)
    {
      cell = cell->getCellBelow();
      cell->setType(type);
      cell->setIsOccupied(true); // Set Below Cell to true
                                 // Set Cell to the Below Cell
    }
    topLeftPoint.row += 1;
    return true;
  }
  return false;
}

std::shared_ptr<Block> Block::makeBlock(Level level, BlockType type,
                                        std::shared_ptr<Score> score,
                                        std::shared_ptr<Grid> g)
{
  std::shared_ptr<Block> pBlock;
  switch (type)
  {
  case BlockType::I:
    pBlock = std::make_shared<IBlock>(level, type, score);
    break;
  case BlockType::J:
    pBlock = std::make_shared<JBlock>(level, type, score);
    break;
  case BlockType::L:
    pBlock = std::make_shared<LBlock>(level, type, score);
    break;
  case BlockType::O:
    pBlock = std::make_shared<OBlock>(level, type, score);
    break;
  case BlockType::S:
    pBlock = std::make_shared<SBlock>(level, type, score);
    break;
  case BlockType::Z:
    pBlock = std::make_shared<ZBlock>(level, type, score);
    break;
  case BlockType::T:
    pBlock = std::make_shared<TBlock>(level, type, score);
    break;
  case BlockType::U:
    pBlock = std::make_shared<UBlock>(level, type, score);
    break;
  case BlockType::NoType:
    break;
  }
  pBlock->init(g);
  return pBlock;
}
