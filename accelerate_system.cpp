#include "accelerate_system.h"

#include "logger.h"
 
AccelerateSystem::AccelerateSystem(EntityManager &entity_manager, World &world) :
	System(entity_manager, world) {
}


void AccelerateSystem::update() {
	update_entities();
}

void AccelerateSystem::update_entity(int id) {
	PositionComponent *position = entity_manager.get<PositionComponent>(id);
	MovementComponent *movement = entity_manager.get<MovementComponent>(id);
	if (movement != NULL && position != NULL && movement->state == MovementComponent::STARTING) {
		Position offset = movement_to_offset(movement);
		Position target = {position->current.y + offset.y, position->current.x + offset.x};
		target = keep_in_bounds(target);

		movement->in_motion = 0;
		movement->path = create_path(position->current, target);
		movement->steps = movement->speed;

		movement->state = MovementComponent::MOVING;
	}
}

Position AccelerateSystem::keep_in_bounds(Position target) {
	if (target.y > world.get_height() - 1) {
		target.y = world.get_height() - 1;
	} else if (target.y < 0) {
		target.y = 0;
	}

	if (target.x > world.get_width() - 1) {
		target.x = world.get_width() - 1;
	} else if (target.x < 0) {
		target.x = 0;
	}

	return target;
}


Position AccelerateSystem::movement_to_offset(MovementComponent *movement) {
	Position offset = {0, 0};
	int distance = movement->distance;

	switch(movement->direction) {
		case Direction::NONE:
			offset = {0, 0};
			break;
		case Direction::NORTH:
			offset = {-distance, 0};
			break;
		case Direction::EAST:
			offset = {0, -distance};
			break;
		case Direction::SOUTH:
			offset = {distance, 0};
			break;
		case Direction::WEST:
			offset = {0, distance};
			break;
	}

	return offset;
}

std::vector<Position> AccelerateSystem::create_path(Position start, Position end) {
	std::vector<Position> path;
	path.push_back(start);

	int x_increment, y_increment;

	if (start.x > end.x) {
		x_increment = -1;
	} else if (start.x < end.x) {
		x_increment = 1;
	} else {
		x_increment = 0;
	}

	if (start.y > end.y) {
		y_increment = -1;
	} else if (start.y < end.y) {
		y_increment = 1;
	} else {
		y_increment = 0;
	}

	for (int y = start.y + y_increment, x = start.x + x_increment; 
			y != end.y || x != end.x;
			y += y_increment, x += x_increment) {

		path.push_back(Position(y, x));
	}

	path.push_back(end);

	return path;
}
