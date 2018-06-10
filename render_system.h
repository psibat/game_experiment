#include <ncurses.h>

#include "system.h"
#include "world.h"

#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

class RenderSystem : private System {
	public:
		RenderSystem(EntityManager &entity_manager, World &world, WINDOW *window = stdscr);

		WINDOW *window;
		int height, width;

		int offset_y, offset_x;

		void set_window(WINDOW *window);

		void update();

	private:
		void update_entity(int id);
		void update_world();

		int calc_offset(int screen_dimension, int center);
};

#endif
