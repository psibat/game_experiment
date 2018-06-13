#include "system.h"
 
System::System(EntityManager &entity_manager, World &world) : 
	entity_manager(entity_manager),
	world(world){ }

void System::update_entities() {
	for (int id = 0; id < MAX_ENTITIES; id++) {
		if (entity_manager.exists(id)) {
			update_entity(id);
		}
	}
}
