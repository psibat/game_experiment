#include "component.h"

#include <vector>
#include "position.h"

#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

struct MovementComponent : public Component {
	MovementComponent();

	// Position in path
	int in_motion = -1;

	// Steps to move through path per tick
	int steps = 0;

	// Path
	std::vector<Position> path;
};

#endif
