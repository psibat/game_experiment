#include "movement_system.h"

#include "logger.h"
 
MovementSystem::MovementSystem(EntityManager &entity_manager, World &world) :
	System(entity_manager),
	world(world) {
	
	}

void MovementSystem::update() {
	update_entities();
}

void MovementSystem::update_entity(int id) {
	PositionComponent *position = entity_manager.get_position(id);
	MovementComponent *movement = entity_manager.get_movement(id);
	if (position != NULL && movement != NULL) {
		Position offset = movement_to_offset(movement);
		Position target = {position->current.y + offset.y, position->current.x + offset.x};
		target = keep_in_bounds(target);

		position->current = target;


	}
}

Position MovementSystem::keep_in_bounds(Position target) {
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

Position MovementSystem::movement_to_offset(MovementComponent *movement) {
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
