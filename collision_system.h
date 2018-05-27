#include "system.h"

#include "world.h"

#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

class CollisionSystem : public System {
	public:
		CollisionSystem(EntityManager &entity_manager, World &world);

		World &world;
		void work();

};

#endif
