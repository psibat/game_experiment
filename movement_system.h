#include "system.h"

#include <vector>

#include "world.h"

#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

class MovementSystem : public System {
	public:
		MovementSystem(EntityManager &entity_manager, World &world);

		void update();
	private:
		void update_entity(int id);

		void register_collisions(int id, MovementComponent *movement, CollisionComponent *collision);


};

#endif
