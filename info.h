#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>
#include "state.h"
#include "types.h"

struct Info
{
	int row, col;
	bool occupied;
	BlockType type;
};

#endif
