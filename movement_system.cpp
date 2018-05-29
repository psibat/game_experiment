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
		keep_in_bounds(movement, position);

		position->y += movement->y;
		position->x += movement->x;
		movement->y = 0;
		movement->x = 0;

	}
}

void MovementSystem::keep_in_bounds(MovementComponent *movement, PositionComponent *position) {

	int y = position->y + movement->y;
	int x = position->x + movement->x;

	if (y > world.get_height()) {
		movement->y = world.get_height() - position->y;
	} else if (y < 0) {
		movement->y = -position->y;
	}


	log("Movement: " + std::to_string(movement->x));

	if (x > world.get_width()) {
		movement->x = world.get_width() - position->x;
	} else if (x < 0) {
		movement->x = -position->x;
	}


	log("New movement: " + std::to_string(movement->x));

}
