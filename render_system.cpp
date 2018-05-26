#include "render_system.h"

#include <string>
#include <ncurses.h>

#include "logger.h"
 
RenderSystem::RenderSystem(EntityManager &entity_manager) : System(entity_manager){ }

void RenderSystem::work() {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (entity_manager.entity_exists(i)) {
			PositionComponent *position = entity_manager.get_position(i);
			AppearanceComponent *appearance = entity_manager.get_appearance(i);
			if (position != NULL && appearance != NULL) {
				mvaddch(position->y, position->x, appearance->model);
				log("Drawing entity at: " + 
						std::to_string(position->y) + " " + std::to_string( position->x));
			}
		}
	}
}


