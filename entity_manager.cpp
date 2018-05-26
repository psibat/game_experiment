#include "entity_manager.h"
#include "logger.h"

#include <ncurses.h>

 
EntityManager::EntityManager() {
	existance.resize(MAX_ENTITIES);
	position_components.resize(MAX_ENTITIES);
	appearance_components.resize(MAX_ENTITIES);
}

int EntityManager::new_entity() {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (!existance.at(i)) {
			existance.at(i) = true;
			log("New entity ID: " + std::to_string(i));
			return i;
		}
	}

	log("Failed to get new entity");

	return -1;
}

void EntityManager::delete_entity(int id) {
	existance.at(id) = false;
	delete position_components.at(id);
	delete appearance_components.at(id);

	log("Destroyed entity ID: " + std::to_string(id));
}

bool EntityManager::entity_exists(int id) {
	return existance.at(id);
}

void EntityManager::set_position(int id, PositionComponent* position) {
	position_components.at(id) = position;
}

PositionComponent *EntityManager::get_position(int id) {
	return position_components.at(id);
}

void EntityManager::set_appearance(int id, AppearanceComponent* appearance) {
	appearance_components.at(id) = appearance;
}

AppearanceComponent *EntityManager::get_appearance(int id) {
	return appearance_components.at(id);
}
