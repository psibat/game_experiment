#include "coordinates.h"

#ifndef POSITION
#define POSITION

struct Position : public Coordinates {
	Position(int y, int x) : Coordinates(y, x) {};
};


#endif
