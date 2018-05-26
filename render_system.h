#include "system.h"

#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM

class RenderSystem : private System {
	public:
		RenderSystem(EntityManager &entity_manager);

		void work();
};

#endif
