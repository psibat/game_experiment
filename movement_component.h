#include "component.h"

#include "direction.h"

#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

struct MovementComponent : public Component {
	MovementComponent();

	Direction direction;
	int distance;
	int duration;
};

#endif
