#ifndef TYPES_H
#define TYPES_H

#include <string>
// Contains possible block types
enum class BlockType
{
	I,
	J,
	L,
	O,
	S,
	Z,
	T,
	U,
	NoType
};

class typeFunctions
{

  public:
	static BlockType getBlockType(std::string bt)
	{
		if (bt == "J")
		{
			return BlockType::J;
		}
		else if (bt == "L")
		{
			return BlockType::L;
		}
		else if (bt == "O")
		{
			return BlockType::O;
		}
		else if (bt == "S")
		{
			return BlockType::S;
		}
		else if (bt == "Z")
		{
			return BlockType::Z;
		}
		else if (bt == "T")
		{
			return BlockType::T;
		}
		else if (bt == "I")
		{
			return BlockType::I;
		}
		else if (bt == "U")
		{
			return BlockType::U;
		}
		else
		{
			return BlockType::NoType;
		}
	}
};

// Contains the possible levels
enum class Level
{
	l0,
	l1,
	l2,
	l3,
	l4
};
#endif
