#include "entity_manager.h"

#ifndef SYSTEM
#define SYSTEM

class System {
	public:
		System(EntityManager &entity_manager);

		EntityManager &entity_manager;

		virtual void work() = 0;
	private:
};

#endif
