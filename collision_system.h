#include "system.h"

#ifndef COLLISION_SYSTEM
#define COLLISION_SYSTEM

class CollisionSystem : public System {
	public:
		CollisionSystem(EntityManager &entity_manager);

		void work();

};

#endif
