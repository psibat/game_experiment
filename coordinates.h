#include "component.h"

#ifndef COORDINATES
#define COORDINATES

struct Coordinates : public Component {
		Coordinates(int y, int x);

		int y;
		int x;
};

#endif
