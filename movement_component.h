#include "coordinates_component.h"

#ifndef MOVEMENT_COMPONENT
#define MOVEMENT_COMPONENT

struct MovementComponent : public CoordinatesComponent {
	MovementComponent(int y, int x) : CoordinatesComponent(y, x) {};
};

#endif
