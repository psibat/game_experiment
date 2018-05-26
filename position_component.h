#include "coordinates_component.h"

#ifndef POSITION
#define POSITION

struct PositionComponent : public CoordinatesComponent {
	PositionComponent(int y, int x) : CoordinatesComponent(y, x) {};
};


#endif
