#include <vector>
#include <map>

#include "position_component.h"
#include "appearance_component.h"

#ifndef ENTITY_MANAGER
#define ENTITY_MANAGER

static const int MAX_ENTITIES = 200;

class EntityManager {
	public:
		EntityManager();

		int new_entity();
		void delete_entity(int id);
		bool entity_exists(int id);

		void set_position(int id, PositionComponent* position);
		PositionComponent *get_position(int id);

		void set_appearance(int id, AppearanceComponent* appearance);
		AppearanceComponent *get_appearance(int id);

	private:
		std::vector<bool> existance;
		std::vector<PositionComponent *> position_components;
		std::vector<AppearanceComponent *> appearance_components;

};

#endif
