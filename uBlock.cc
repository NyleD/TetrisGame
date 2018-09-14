#include "uBlock.h"
#include "grid.h"
#include "exception.h"

UBlock::UBlock(Level level, BlockType type, std::shared_ptr<Score> score)
	: Block2{level, type, score} {}

void UBlock::init(std::shared_ptr<Grid> g)
{
	auto grid = g->getGrid();

	cells.emplace_back(grid.at(3).at(5));
	initCells();
}
