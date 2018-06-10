#include "screen.h"

#include "entity_manager.h"
#include "world.h"

#include "render_system.h"
#include "movement_system.h"
#include "accelerate_system.h"

#ifndef ENGINE_H
#define ENGINE_H

class Engine {
	public:
		Engine();

		enum State {
			STOP,
			GAMEPLAY
		};

		void start();
		void stop();
	private:
		Screen scr;
		EntityManager entity_manager;
		World world;
		State state;

		// World loader (Either class or method)

		// Systems
		RenderSystem render_system;
		AccelerateSystem accelerate_system;
		MovementSystem movement_system;

		void process();
		void draw();

};

#endif
