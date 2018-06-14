#include "system.h"

#include "world.h"

#ifndef ACCELERATE_SYSTEM_H
#define ACCELERATE_SYSTEM_H

class AccelerateSystem : public System {
	public:
		AccelerateSystem(EntityManager &entity_manager, World &world);

		void update();
	
	private:
		void update_entity(int id);

		Position keep_in_bounds(Position target);

		Position movement_to_offset(MovementComponent *movement);

		std::vector<Position> create_path(Position start, Position end);
};

#endif
