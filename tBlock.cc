#include "tBlock.h"
#include "grid.h"
#include "exception.h"

TBlock::TBlock(Level level, BlockType type, std::shared_ptr<Score> score)
	: Block3{level, type, score} {}

void TBlock::init(std::shared_ptr<Grid> g) {
	auto grid = g->getGrid();

	cells.emplace_back(grid.at(3).at(0));
	cells.emplace_back(grid.at(3).at(1));
	cells.emplace_back(grid.at(3).at(2));
	cells.emplace_back(grid.at(4).at(1));

	initCells();
}
