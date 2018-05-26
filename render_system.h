#include <ncurses.h>

#include "system.h"

#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

class RenderSystem : private System {
	public:
		RenderSystem(EntityManager &entity_manager);

		void work();
		void work(WINDOW *window);

	private:
		void render(WINDOW *window);
		int calc_offset(int screen_dimension, int center);
};

#endif
