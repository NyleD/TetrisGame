#ifndef SCORE_H
#define SCORE_H
#include <memory>
#include "types.h"

class Score
{
	int currentScore = 0;
	int highScore = 0;
	void updateHighScore();

  public:
	void updateCurrentScore(const Level level, int filledRowsCount = 1);
	int getCurrentScore() const;
	int getHighScore() const;
};

#endif
