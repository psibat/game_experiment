#include <ncurses.h>
#include "render_system.h"
 
RenderSystem::RenderSystem(EntityManager &entity_manager) : System(entity_manager){ }

void RenderSystem::work() {
	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (entity_manager.exist(i)) {
			Position *position = entity_manager.position(i);
			Appearance *appearance = entity_manager.appearance(i);
			mvaddch(position->y, position->x, appearance->model);
		}
	}
}


