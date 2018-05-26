#include "coordinates_component.h"

#ifndef POSITION_H
#define POSITION_H

struct PositionComponent : public CoordinatesComponent {
	PositionComponent(int y, int x) : CoordinatesComponent(y, x) {};
};


#endif
