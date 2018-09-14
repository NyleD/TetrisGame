#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <memory>
#include "types.h"

class Grid;
class TextDisplay;
class Game
{
	bool textonly = false;

  protected:
	std::shared_ptr<TextDisplay> td;
	std::shared_ptr<Grid> g;
	Level currentLevel;
	int num_blocks_created;
	void shiftDown(int n);

  public:
	Game(bool textonly, Level level);
	virtual ~Game();
	virtual void determineNextBlock(bool change_current = true,
									std::string block = "") = 0;
	virtual void rotateClockwise(int n);
	virtual void rotateCounterClockwise(int n);
	virtual void shiftLeft(int n);
	virtual void shiftRight(int n);

	void dropBlock();

	friend std::ostream &operator<<(std::ostream &out, const Game &g);
};

#endif
