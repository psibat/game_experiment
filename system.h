#include "entity_manager.h"
#include "world.h"

#ifndef SYSTEM_H
#define SYSTEM_H

class System {
	public:
		System(EntityManager &entity_manager, World &world);

		virtual void update() = 0;

	protected:
		void update_entities();

		EntityManager &entity_manager;
		World &world;

	private:
		virtual void update_entity(int id) = 0;
};

#endif
