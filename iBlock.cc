#include "iBlock.h"

IBlock::IBlock(Level level, BlockType type, std::shared_ptr<Score> score)
	: Block4(level, type, score) {}

void IBlock::init(std::shared_ptr<Grid> g)
{
	auto grid = g->getGrid();

	cells.emplace_back(grid.at(3).at(0));
	cells.emplace_back(grid.at(3).at(1));
	cells.emplace_back(grid.at(3).at(2));
	cells.emplace_back(grid.at(3).at(3));

	initCells();
}
