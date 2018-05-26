#include "system.h"

#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

class RenderSystem : private System {
	public:
		RenderSystem(EntityManager &entity_manager);

		void work();
};

#endif
