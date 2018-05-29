#include "system.h"

#include "world.h"

#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

class CollisionSystem : public System {
	public:
		CollisionSystem(EntityManager &entity_manager, World &world);

		void update();
	
	private:
		World &world;

		void update_entity(int id);

};

#endif
