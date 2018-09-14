#include "textdisplay.h"
#include "cell.h"

TextDisplay::TextDisplay()
{
    // set all cells to " " symbol

    for (int r = 0; r < 15; ++r)
    {
        std::vector<char> v;
        theDisplay.push_back(v);
    }

    for (int r = 0; r < 15; ++r)
    {
        for (int c = 0; c < 11; ++c)
        {
            theDisplay.at(r).emplace_back(' ');
        }
    }
}

//////LEVEL DISPLAY////////
void TextDisplay::setLevel(int n)
{
    theLevel = n;
}

//////SCORE DISPLAY////////
void TextDisplay::setScoreObject(std::shared_ptr<Score> s)
{
    score = s;
}

//////CELL DISPLAY/////////
void TextDisplay::notify(Subject<Info, State> &whoNotified)
{

    char typeDisplay;

    Info info = whoNotified.getInfo();

    BlockType btype = info.type;

    if (info.occupied)
    {

        switch (btype)
        {
        case BlockType::I:
            typeDisplay = 'I';
            break;
        case BlockType::J:
            typeDisplay = 'J';
            break;
        case BlockType::L:
            typeDisplay = 'L';
            break;
        case BlockType::O:
            typeDisplay = 'O';
            break;
        case BlockType::S:
            typeDisplay = 'S';
            break;
        case BlockType::Z:
            typeDisplay = 'Z';
            break;
        case BlockType::T:
            typeDisplay = 'T';
            break;
        case BlockType::U:
            typeDisplay = '*';
            break;
        case BlockType::NoType:
            typeDisplay = ' ';
            break;
        }
    }
    else
    {
        typeDisplay = ' ';
    }

    size_t row = info.row;
    size_t col = info.col;

    theDisplay.at(row).at(col) = typeDisplay;
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td)
{

    out << "Level:  " << td.theLevel << std::endl;
    out << "Highscore: " << td.score->getHighScore() << std::endl;
    out << "Score:  " << td.score->getCurrentScore() << std::endl;
    out << "-----------" << std::endl;

    for (int i = 0; i < td.rowSize; i++)
    {
        for (int j = 0; j < td.colSize; j++)
        {
            out << td.theDisplay.at(i).at(j);
        }
        out << std::endl;
    }

    out << "-----------" << std::endl;

    return out;
}
