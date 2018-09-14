#include "oBlock.h"
#include "exception.h"
#include "grid.h"

OBlock::OBlock(Level level, BlockType type, std::shared_ptr<Score> score)
	: Block2{level, type, score} {}

void OBlock::init(std::shared_ptr<Grid> g)
{
	auto grid = g->getGrid();

	cells.emplace_back(grid.at(3).at(0));
	cells.emplace_back(grid.at(3).at(1));
	cells.emplace_back(grid.at(4).at(0));
	cells.emplace_back(grid.at(4).at(1));

	initCells();
}
