#include "component.h"

#ifndef COORDINATES_COMPONENT_H
#define COORDINATES_COMPONENT_H

struct CoordinatesComponent : public Component {
		CoordinatesComponent(int y, int x);

		int y;
		int x;
};

#endif
