#include "coordinates_component.h"

#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

struct MovementComponent : public CoordinatesComponent {
	MovementComponent(int y, int x) : CoordinatesComponent(y, x) {};
};

#endif
