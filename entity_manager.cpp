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

void EntityManager::delete_entity(int i) {
	exists.at(i) = false;
	delete positions.at(i);
	delete appearances.at(i);

	log("Destroyed entity ID: " + std::to_string(i));

}

void EntityManager::render() {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (exists.at(i)) {
			Position *position = positions.at(i);
			Appearance *appearance = appearances.at(i);
			mvaddch(position->y, position->x, appearance->model);
		}
	}

}

void EntityManager::createMan(int y, int x) {
	int id = new_entity();
	positions.at(id) = new Position(y, x);
	appearances.at(id) = new Appearance('@');

}
