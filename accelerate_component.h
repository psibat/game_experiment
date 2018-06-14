#include "component.h"

#include "direction.h"

#ifndef ACCELERATE_COMPONENT_H
#define ACCELERATE_COMPONENT_H

struct AccelerateComponent : public Component {
		AccelerateComponent();

		// Direction to make path
		Direction direction;

		// Distance to travel in direction
		int distance;

		// Steps to take per tick
		int speed;
};

#endif
