#include "render_system.h"

#include <string>

#include "logger.h"
 
RenderSystem::RenderSystem(EntityManager &entity_manager, World &world) : 
	System(entity_manager),
	world(world)
{ }

void RenderSystem::work() { render(stdscr); }

void RenderSystem::work(WINDOW *window) { render(window); }

void RenderSystem::render(WINDOW *window) {
	PositionComponent *center = entity_manager.get_position(entity_manager.get_center());
	int height;
	int width;
	getmaxyx(window, height, width);
	int offset_y = calc_offset(height, center->y);
	int offset_x = calc_offset(width, center->x);

	render_world(window, offset_y, offset_x);

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

void RenderSystem::render_world(WINDOW *window, int offset_y, int offset_x) {
	for (int y = 0; y < world.get_height(); y++) {
		for (int x = 0; x < world.get_width(); x++) {
			char model = world.get_tile(y, x) == World::Wall ? '#' : ' '; 
			mvwaddch(window, y + offset_y, x + offset_x, model);
			if (world.get_tile(y, x) == World::Wall) {
			}
		}
	}
}


int RenderSystem::calc_offset(int screen_dimension, int center) {
	return (screen_dimension / 2) - center;
}
