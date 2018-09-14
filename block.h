#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <memory>
#include "score.h"
#include "types.h"
#include "point.h"
#include "observer.h"
#include "info.h"
#include "cell.h"
class Cell;
class Grid;

class Block : public std::enable_shared_from_this<Block>,
                public Observer<Info, State>
{
  protected:
    // Currently occupying Cells
    std::vector<std::shared_ptr<Cell>> cells;
    // Score
    std::shared_ptr<Score> score;
    // Level at which this Block was generated
    const Level level;
    // Type of Block
    const BlockType type;

    Point topLeftPoint;

    bool myCell(int checkRow, int checkCol);

  public:
    Block(Level level, BlockType type, std::shared_ptr<Score> score);
    virtual ~Block() = 0;
    virtual void rotateCMappings(Point &p) = 0;
    virtual void rotateCCMappings(Point &p) = 0;

    // init initializes this Block at topLeftPoint
    // and invokes initCells
    virtual void init(std::shared_ptr<Grid> g) = 0;

    BlockType getBlockType();

    // initCells initializes each Cell in cells with this Block and
    // throws EndOfGameException when the Grid does not have
    // enough room for the current Block
    void initCells();

    bool rotateCell(std::shared_ptr<Cell> cell, std::string direction,
                    std::vector<std::vector<std::shared_ptr<Cell>>> &theGrid,
                    int gridHeight, int gridWidth);

    std::vector<std::shared_ptr<Cell>> getCells();

    void notify(Subject<Info, State> &whoNotified) override;

    // Transformations
    bool rotateClockwise(std::shared_ptr<Grid> g);
    bool rotateCounterClockwise(std::shared_ptr<Grid> g);
    bool shiftLeft();
    bool shiftRight();
    bool shiftDown();

    // makeBlock makes a new Block of bType
    static std::shared_ptr<Block> makeBlock(Level level, BlockType type,
                                            std::shared_ptr<Score> score,
                                            std::shared_ptr<Grid> g);
};

#endif
