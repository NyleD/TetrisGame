#include "cell.h"

Cell::Cell(int row, int col, bool occupied)
: r{row}, c{col}, occupied{occupied} {}

void Cell::setCellRelationships(std::shared_ptr<Cell> above,
                                std::shared_ptr<Cell> below,
                                std::shared_ptr<Cell> right,
                                std::shared_ptr<Cell> left)
{
  cellAbove = above;
  cellBelow = below;
  cellRight = right;
  cellLeft = left;
}

// Return The Cells Neighbours
std::shared_ptr<Cell> Cell::getCellAbove()
{
  return cellAbove;
}
std::shared_ptr<Cell> Cell::getCellBelow()
{
  return cellBelow;
}
std::shared_ptr<Cell> Cell::getCellRight()
{
  return cellRight;
}
std::shared_ptr<Cell> Cell::getCellLeft()
{
  return cellLeft;
}

bool Cell::getIsOccupied()
{
  return occupied;
}

void Cell::setIsOccupied(bool occupied)
{
  this->occupied = occupied;
  struct State myState
  {
    StateType::Display
  };
  setState(myState);
  notifyObservers();
}

bool Cell::directionFrom(int fromRow)
{
  if (fromRow > r)
  {
    return true; // notified from above
  }
  return false; // notified from below
}

void Cell::deleteCellData()
{ // will clear this cell;
  setType(BlockType::NoType);
  setIsOccupied(false);
}

void Cell::clearCell()
{
  deleteCellData();
  // Set My State
  struct State myState
  {
    StateType::Clear
  }; // Direction unimportant
  setState(myState);
  notifyObservers();
}

void Cell::setType(BlockType t)
{
  type = t;
}

// This Cell's neighbours will call this
// when they've changed state
void Cell::notify(Subject<Info, State> &whoFrom)
{

  // New logic use StateType and the direction this is coming from

  State fromState = whoFrom.getState();
  Info fromInfo = whoFrom.getInfo();
  if (fromState.type == StateType::Clear)
  { // Clears State

    if (directionFrom(fromInfo.row))
    { // From Above
      // Do Nothing since this Cell is below the cleared row
    }
    else if (!directionFrom(fromInfo.row))
    { // From Below
      struct State myState
      {
        StateType::MoveDown
      };
      setState(myState);
      notifyObservers();
    }
  }

  if (fromState.type == StateType::MoveDown)
  { // Move Down State

    if (directionFrom(fromInfo.row))
    {                               // From Above
      occupied = fromInfo.occupied; // Copy the Value Down -> Stop
    }
    else if (!directionFrom(fromInfo.row))
    {                    // From Below
      notifyObservers(); // Turn Move Down State  Notify
    }
  }
}

Info Cell::getInfo() const
{
  struct Info info
  {
    r, c, occupied, type
  };
  return info;
}
