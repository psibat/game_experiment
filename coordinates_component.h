#include "component.h"

#ifndef COORDINATES_COMPONENT
#define COORDINATES_COMPONENT

struct CoordinatesComponent : public Component {
		CoordinatesComponent(int y, int x);

		int y;
		int x;
};

#endif
