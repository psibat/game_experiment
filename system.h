#include "entity_manager.h"

#ifndef SYSTEM_H
#define SYSTEM_H

class System {
	public:
		System(EntityManager &entity_manager);

		EntityManager &entity_manager;

		virtual void work() = 0;
	private:
};

#endif
