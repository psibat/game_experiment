#include "entity_manager.h"
#include "logger.h"

#include <ncurses.h>
 
EntityManager::EntityManager() {
	exists.resize(MAX_ENTITIES);
	positions.resize(MAX_ENTITIES);
	appearances.resize(MAX_ENTITIES);
}

int EntityManager::new_entity() {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (!exists.at(i)) {
			exists.at(i) = true;
			log("New entity ID: " + std::to_string(i));
			return i;
		}
	}

	log("Failed to get new entity");
	return -1;
}

void EntityManager::delete_entity(int id) {
	exists.at(id) = false;
	delete positions.at(id);
	delete appearances.at(id);

	log("Destroyed entity ID: " + std::to_string(id));
}

Position *EntityManager::position(int id) {
	return positions.at(id);
}

Appearance *EntityManager::appearance(int id) {
	return appearances.at(id);
}

bool EntityManager::exist(int id) {
	return exists.at(id);
}

int EntityManager::createMan(int y, int x) {
	int id = new_entity();
	positions.at(id) = new Position(y, x);
	appearances.at(id) = new Appearance('@');

	return id;
}
