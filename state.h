#ifndef STATE_H
#define STATE_H

/* StateTypes are:
    Clear -- I am being removed. I'm letting you know that I am being removed
    so you can send me your value.

    MoveDown -- I have a neighbour (or a neighbour's neighbour, etc.) who is a
             new piece, not of my colour, and is a straight line away from me.
             I'm letting you know that that neighbour exists, and in which
             direction it is, in case you need to change colour.
    
    I am a Cell by the way. :)
*/
enum class StateType
{
    Clear,
    MoveDown,
    Display
};

struct State
{
    StateType type; // See above
};

#endif
