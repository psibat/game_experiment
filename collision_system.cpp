#include "collision_system.h"
 
CollisionSystem::CollisionSystem(EntityManager &entity_manager, World &world) : 
	System(entity_manager),
	world(world)
{ }

void CollisionSystem::work() {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (entity_manager.entity_exists(i)) {
			PositionComponent *position = entity_manager.get_position(i);
			MovementComponent *movement = entity_manager.get_movement(i);
			if (position != NULL && movement != NULL) {
				int y = position->y + movement->y;
				if (y > world.get_height() || y < 0 ) {
					movement->y = 0;
				}


				int x = position->x + movement->x;
				if (x > world.get_width() || x < 0 ) {
					movement->x = 0;
				}
			}
		}
	}
}
