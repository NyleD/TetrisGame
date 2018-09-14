#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "info.h"
#include "subject.h"
#include "types.h"
#include "block.h"

class Cell;
class Score;

class TextDisplay : public Observer<Info, State>
{
  std::vector<std::vector<char>> theDisplay;

  const int rowSize = 15;
  const int colSize = 11;
  int theLevel = 0;

  std::shared_ptr<Score> score;

public:
  TextDisplay();
  void setScoreObject(std::shared_ptr<Score> s);
  void setScore(int n);
  void setLevel(int n);
  void notify(Subject<Info, State> &whoNotified) override;

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
