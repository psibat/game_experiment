#include "system.h"

#ifndef MOVEMENT_SYSTEM
#define MOVEMENT_SYSTEM

class MovementSystem : public System {
	public:
		MovementSystem(EntityManager &entity_manager);
		void work();

};

#endif
