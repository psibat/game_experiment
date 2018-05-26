#include "system.h"

#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

class CollisionSystem : public System {
	public:
		CollisionSystem(EntityManager &entity_manager);

		void work();

};

#endif
