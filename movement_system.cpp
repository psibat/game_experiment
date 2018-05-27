#include "movement_system.h"
 
MovementSystem::MovementSystem(EntityManager &entity_manager) : System(entity_manager) { }

void MovementSystem::work() {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (entity_manager.entity_exists(i)) {
			PositionComponent *position = entity_manager.get_position(i);
			MovementComponent *movement = entity_manager.get_movement(i);
			if (position != NULL && movement != NULL) {
				position->y += movement->y;
				position->x += movement->x;
				movement->y = 0;
				movement->x = 0;
			}

		}
	}
}
