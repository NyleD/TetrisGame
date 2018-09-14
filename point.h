#ifndef POINT_H
#define POINT_H

struct Point
{
	int col;
	int row;
	Point(int col, int row) : col{col}, row{row} {}
};

#endif
