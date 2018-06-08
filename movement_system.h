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
		World &world;

		void update_entity(int id);

		Position keep_in_bounds(Position target);
		
		Position movement_to_offset(MovementComponent *movement);

};

#endif
