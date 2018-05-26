#include <vector>

#include "position.h"
#include "appearance.h"

#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER

static const int MAX_ENTITIES = 200;

class EntityManager {
	public:
		EntityManager();

		int new_entity();
		void delete_entity(int i);

		void render();

		void createMan(int y, int x);

		
	private:
		std::vector<bool> exists;
		std::vector<Position *> positions;
		std::vector<Appearance *> appearances;

};

#endif
