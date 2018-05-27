#include "system.h"

#include "world.h"

#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

class MovementSystem : public System {
	public:
		MovementSystem(EntityManager &entity_manager, World &world);
		void work();
	private:
		World &world;

};

#endif
