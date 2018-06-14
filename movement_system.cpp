#include "movement_system.h"

#include "logger.h"
#include <algorithm>
 
MovementSystem::MovementSystem(EntityManager &entity_manager, World &world) :
	System(entity_manager, world) {
	
	}

void MovementSystem::update() {
	update_entities();
}

void MovementSystem::update_entity(int id) {
	PositionComponent *position = entity_manager.get<PositionComponent>(id);
	MovementComponent *movement = entity_manager.get<MovementComponent>(id);
	CollisionComponent *collision = entity_manager.get<CollisionComponent>(id);
	if (movement != NULL && position != NULL && movement->state == MovementComponent::MOVING) {

		if (collision != NULL && collision->tangible) {
			register_collisions(id, movement, collision);
		} else {
			movement->in_motion = std::min(movement->in_motion + movement->steps,
					(int) movement->path.size() -1);
		}

		position->current = movement->path.at(movement->in_motion);
	}

}

void MovementSystem::register_collisions(int id, MovementComponent *movement,
		CollisionComponent *collision) {
	bool blocked = false;

	// While not blocked go through path
	for (int i = 0;
			i < movement->steps && movement->in_motion < (int) movement->path.size() - 1 && !blocked;
			i++) {

		// Move along path
		movement->in_motion++;
		Position current_position = movement->path.at(movement->in_motion);

		// Check if blocked by terrain
		blocked = collision->passable_terrain.count(world.get_tile(current_position)) == 0;

		// Go through all other entities and check collision
		for (int other_id = 0; other_id < MAX_ENTITIES && !blocked; other_id++) {
			if (other_id != id && entity_manager.exists(other_id)) {
				CollisionComponent *other_collision = entity_manager.get<CollisionComponent>(other_id);
				PositionComponent *other_position = entity_manager.get<PositionComponent>(other_id);

				// If the other entity has collision and is at the same position
				if (other_collision != NULL && other_collision->tangible &&
						other_position != NULL && other_position->current == current_position) {
					// Save id of collided with entity for collision system
					collision->collided_with = other_id;
					blocked = true;
				}

			}
		}

	}
	
	// If blocked by entity/terrain erase rest of path and go back to before blocker
	if (blocked) {
		movement->path.erase(movement->path.begin() + movement->in_motion, movement->path.end());
		movement->in_motion--;
		log("HIT");
	}

	if (movement->in_motion == (int) movement->path.size() - 1) {
		movement->state = MovementComponent::HALTED;
		log("Stopping");
	}
}
