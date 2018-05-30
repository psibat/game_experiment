#include "component.h"

#include <vector>

#include "position.h"

#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

struct MovementComponent : public Component {
	MovementComponent();

	std::vector<Position> path;
	int speed;
};

#endif
