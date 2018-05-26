#include <ncurses.h>

#include "system.h"
#include "world.h"

#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

class RenderSystem : private System {
	public:
		RenderSystem(EntityManager &entity_manager, World  &world);

		World &world;

		void work();
		void work(WINDOW *window);

	private:
		void render(WINDOW *window);
		void render_world(WINDOW *window, int offset_y, int offset_x);
		int calc_offset(int screen_dimension, int center);
};

#endif
