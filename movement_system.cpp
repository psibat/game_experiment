#include "movement_system.h"

#include "logger.h"
 
MovementSystem::MovementSystem(EntityManager &entity_manager, World &world) :
	System(entity_manager, world) {
	
	}

void MovementSystem::update() {
	update_entities();
}

void MovementSystem::update_entity(int id) {
	PositionComponent *position = entity_manager.get_position(id);
	MovementComponent *movement = entity_manager.get_movement(id);
	if (movement != NULL && position != NULL) {
		for (int i = 0;
				i < movement->steps && movement->in_motion < (int) movement->path.size() - 1;
				i++, movement->in_motion++) {
		}
		position->current = movement->path.at(movement->in_motion);
	}

}

