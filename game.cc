#include "game.h"
#include "textdisplay.h"
#include "grid.h"

Game::~Game() {}

Game::Game(bool textonly, Level level)
: textonly{textonly}, td{std::make_shared<TextDisplay>()},
g{std::make_shared<Grid>()}, currentLevel{level}
{
	g->init(15, 11, currentLevel, td);
}

void Game::rotateClockwise(int n)
{
	g->rotateClockwise(n);
}

void Game::rotateCounterClockwise(int n)
{
	g->rotateCounterClockwise(n);
}

void Game::shiftLeft(int n)
{
	g->shiftLeft(n);
}

void Game::shiftRight(int n)
{
	g->shiftRight(n);
}

void Game::shiftDown(int n)
{
	g->shiftDown(n);
}

void Game::dropBlock()
{
	g->dropBlock();
}

std::ostream &operator<<(std::ostream &out, const Game &g)
{
	out << *(g.td);
	return out;
}
