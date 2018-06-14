#include "component.h"

#include <vector>
#include "position.h"
#include "direction.h"

#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

struct MovementComponent : public Component {
	MovementComponent();

	enum State {
		HALTED,
		STARTING,
		MOVING
	};

	// State of movement
	State state;

	// Starting to move

	// Direction to make path
	Direction direction;

	// Distance to travel in direction
	int distance;

	// Steps to take per tick
	int speed;

	//--

	// Moving

	// Position in path
	int in_motion = -1;

	// Steps to move through path per tick
	int steps = 0;

	// Path
	std::vector<Position> path;
};

#endif
