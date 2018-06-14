#include "entity_manager.h"
#include "logger.h"

#include <ncurses.h>
#include <algorithm>
 
EntityManager::EntityManager() : existence(MAX_ENTITIES) {
}

int EntityManager::create() {
	auto iter = std::find(existence.begin(), existence.end(), false);
	if (iter != existence.end()) {
		*iter = true;
		int id = std::distance(existence.begin(), iter);
		log("New entity ID: " + std::to_string(id));
		return id;
	}

	log("Failed to create new entity");
	return -1;
}

void EntityManager::destroy(int id) {
	existence.at(id) = false;

	if (player == id) player = -1;
	if (center == id) center = -1;

	for (auto &component_list : components) {
		remove(id, component_list.first);
	}

	log("Destroyed entity ID: " + std::to_string(id));
}

bool EntityManager::exists(int id) {
	return existence.at(id);
}

void EntityManager::add(int id, Component *component) {
	const std::type_info* type = &typeid(*component);
	delete components.at(type).at(id);
	components.at(type).at(id) = component;
}

Component *EntityManager::get(int id, const std::type_info *type) {
	return components.at(type).at(id);
}

void EntityManager::remove(int id, const std::type_info *type) {
	delete components.at(type).at(id);
	components.at(type).at(id) = NULL;
}
