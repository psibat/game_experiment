#include "system.h"

#include "world.h"

#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

class MovementSystem : public System {
	public:
		MovementSystem(EntityManager &entity_manager, World &world);

		void update();
	private:
		World &world;

		void update_entity(int id);

};

#endif
