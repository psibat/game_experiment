#include "system.h"

#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

class MovementSystem : public System {
	public:
		MovementSystem(EntityManager &entity_manager);
		void work();

};

#endif
