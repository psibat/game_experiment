#include "collision_system.h"
 
CollisionSystem::CollisionSystem(EntityManager &entity_manager, World &world) : 
	System(entity_manager, world) { 

	}

void CollisionSystem::update() {
	update_entities();
}

void CollisionSystem::update_entity(int id) {
	CollisionComponent *collision = entity_manager.get<CollisionComponent>(id);
	if (collision != NULL) {

	}
}
