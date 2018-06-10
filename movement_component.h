#include "component.h"

#include <vector>
#include "position.h"

#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

struct MovementComponent : public Component {
	MovementComponent();

	int in_motion = -1;
	int steps = 0;
	std::vector<Position> path;
};

#endif
