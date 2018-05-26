#include "render_system.h"

#include <string>

#include "logger.h"
 
RenderSystem::RenderSystem(EntityManager &entity_manager) : System(entity_manager){ }

void RenderSystem::work() {
	render(stdscr);
}

void RenderSystem::work(WINDOW *window) {
	render(window);
}

void RenderSystem::render(WINDOW *window) {
	PositionComponent *center = entity_manager.get_position(entity_manager.get_center());
	int height;
	int width;
	getmaxyx(window, height, width);
	int offset_y = calc_offset(height, center->y);
	int offset_x = calc_offset(width, center->x);

	log(std::to_string(center->y));

	for (int i = 0; i < MAX_ENTITIES; i++) {
		if (entity_manager.entity_exists(i)) {
			PositionComponent *position = entity_manager.get_position(i);
			AppearanceComponent *appearance = entity_manager.get_appearance(i);
			if (position != NULL && appearance != NULL) {
				int y = offset_y + position->y;
				int x = offset_x + position->x;
				mvaddch(y, x, appearance->model);
				log("Drawing entity at: " + std::to_string(y) + " " + std::to_string(x));
			}
		}
	}

}

int RenderSystem::calc_offset(int screen_dimension, int center) {
	return (screen_dimension / 2) - center;
}
