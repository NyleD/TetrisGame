#ifndef CELL_H
#define CELL_H
#include <cstddef>
#include "state.h"
#include "subject.h"
#include "observer.h"
#include "info.h"
#include <iostream>
#include <memory>

class Block;

class Cell : public Subject<Info, State>, public Observer<Info, State>
{

  const int r, c;
  bool occupied;
  bool directionFrom(int fromRow); // Returns true when sent from above
  std::shared_ptr<Cell> cellAbove;
  std::shared_ptr<Cell> cellBelow;
  std::shared_ptr<Cell> cellRight;
  std::shared_ptr<Cell> cellLeft;
  BlockType type;

public:
  Cell(int r, int c, bool occupied = false);

  // Sets the Cells' Neighbours
  void setCellRelationships(std::shared_ptr<Cell> above,
                            std::shared_ptr<Cell> below,
                            std::shared_ptr<Cell> right,
                            std::shared_ptr<Cell> left);

  // Return The Cells Neighbours
  std::shared_ptr<Cell> getCellAbove();
  std::shared_ptr<Cell> getCellBelow();
  std::shared_ptr<Cell> getCellRight();
  std::shared_ptr<Cell> getCellLeft();

  void setType(BlockType t);

  bool getIsOccupied();

  void setIsOccupied(bool occupied);

  void clearCell(); // clears this cell

  void deleteCellData(); // invoked by clearCell

  void notify(Subject<Info, State> &whoFrom) override;

  Info getInfo() const override;
};

#endif
