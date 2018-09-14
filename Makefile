CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror=vla -MMD -g
OBJECTS=main.o interpreter.o game.o level0.o level1.o level2.o level3.o level4.o grid.o cell.o textdisplay.o block.o block2.o block3.o block4.o iBlock.o jBlock.o lBlock.o oBlock.o sBlock.o tBlock.o uBlock.o zBlock.o score.o exception.o

DEPENDS=${OBJECTS:.o=.d}
EXEC=TetrisGameC++


${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean	
