#include "movement_system.h"
 
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

		int y = position->y + movement->y;
		if (y < world.get_height() && y > -1 ) {
			position->y += movement->y;
		}
		movement->y = 0;

		int x = position->x + movement->x;
		if (x < world.get_width() && x > -1 ) {
			position->x += movement->x;
		}
		movement->x = 0;
	}
}
