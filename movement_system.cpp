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
	PositionComponent *position = entity_manager.get_position(id);
	MovementComponent *movement = entity_manager.get_movement(id);
	CollisionComponent *collision = entity_manager.get_collision(id);
	if (movement != NULL && position != NULL) {

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
	for (int i = 0;
			i < movement->steps && movement->in_motion < (int) movement->path.size() - 1;
			i++) {
		movement->in_motion++;
		Position current_position = movement->path.at(movement->in_motion);
		for (int other_id = 0; other_id < MAX_ENTITIES; other_id++) {
			if (other_id != id && entity_manager.entity_exists(other_id)) {
				CollisionComponent *other_collision = entity_manager.get_collision(other_id);
				PositionComponent *other_position = entity_manager.get_position(other_id);

				if (other_collision != NULL && other_collision->tangible &&
						other_position != NULL && other_position->current == current_position) {

					movement->path.erase(movement->path.begin() + movement->in_motion, movement->path.end());
					movement->in_motion--;
					log("HIT");
		log("PATH SIZE: " + std::to_string(movement->path.size()) + " POSITION: " + std::to_string(movement->in_motion));
					return;
				}

			}
		}
	}
}
