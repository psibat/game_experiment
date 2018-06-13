#include "render_system.h"

#include <string>

#include "logger.h"
 
RenderSystem::RenderSystem(EntityManager &entity_manager, World &world, WINDOW *window) : 
	System(entity_manager, world),
	window(window) {
	getmaxyx(window, height, width);
}

void RenderSystem::set_window(WINDOW *window) {
	this->window = window;
}

void RenderSystem::update() {
	PositionComponent *center = entity_manager.get<PositionComponent>(entity_manager.get_center());
	offset_y = calc_offset(height, center->current.y);
	offset_x = calc_offset(width, center->current.x);

	update_world();
	update_entities();
}

void RenderSystem::update_entity(int id) {
	PositionComponent *position = entity_manager.get<PositionComponent>(id);
	AppearanceComponent *appearance = entity_manager.get<AppearanceComponent>(id);
	if (position != NULL && appearance != NULL) {
		int y = offset_y + position->current.y;
		int x = offset_x + position->current.x;
		mvaddch(y, x, appearance->model);
		log("Drawing " + std::to_string(id) + " at: " + 
				std::to_string(position->current.y) + " " + std::to_string(position->current.x));
	}
}

void RenderSystem::update_world() {
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
