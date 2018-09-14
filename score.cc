#include "score.h"
#include <cmath>

void Score::updateHighScore()
{
    if (currentScore > highScore)
    {
        highScore = currentScore;
    }
}

void Score::updateCurrentScore(Level level, int filledRowsCount)
{
    int levelNum;
    switch (level)
    {
    case Level::l0:
        levelNum = 0;
        break;
    case Level::l1:
        levelNum = 1;
        break;
    case Level::l2:
        levelNum = 2;
        break;
    case Level::l3:
        levelNum = 3;
        break;
    case Level::l4:
        levelNum = 4;
    }
    currentScore += std::pow(levelNum + filledRowsCount, 2);
    updateHighScore();
}

int Score::getCurrentScore() const
{
    return currentScore;
}
int Score::getHighScore() const
{
    return highScore;
}
