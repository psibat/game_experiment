#include "entity_manager.h"
#include "logger.h"

#include <ncurses.h>
 
EntityManager::EntityManager() :
	existence(MAX_ENTITIES),
	position_components(MAX_ENTITIES),
	movement_components(MAX_ENTITIES),
	appearance_components(MAX_ENTITIES)
{}

int EntityManager::new_entity() {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (!existence.at(i)) {
			existence.at(i) = true;
			log("New entity ID: " + std::to_string(i));
			return i;
		}
	}

	log("Failed to get new entity");

	return -1;
}

void EntityManager::delete_entity(int id) {
	existence.at(id) = false;

	if (player == id) player = -1;
	if (center == id) center = -1;

	delete position_components.at(id);
	delete movement_components.at(id);
	delete appearance_components.at(id);

	log("Destroyed entity ID: " + std::to_string(id));
}

bool EntityManager::entity_exists(int id) {
	return existence.at(id);
}

void EntityManager::set_player(int id) {
	player = id;
}

int EntityManager::get_player() {
	return player;
}

void EntityManager::set_center(int id) {
	center = id;
}

int EntityManager::get_center() {
	return center;
}

void EntityManager::set_position(int id, PositionComponent* position) {
	position_components.at(id) = position;
}

PositionComponent *EntityManager::get_position(int id) {
	return position_components.at(id);
}

void EntityManager::set_movement(int id, MovementComponent* movement) {
	movement_components.at(id) = movement;
}

MovementComponent *EntityManager::get_movement(int id) {
	return movement_components.at(id);
}

void EntityManager::set_appearance(int id, AppearanceComponent* appearance) {
	appearance_components.at(id) = appearance;
}

AppearanceComponent *EntityManager::get_appearance(int id) {
	return appearance_components.at(id);
}
