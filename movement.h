#include "coordinates.h"

#ifndef MOVEMENT
#define MOVEMENT

struct Movement : public Coordinates {
	Movement(int y, int x) : Coordinates(y, x) {};
};

#endif
