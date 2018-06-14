#include "screen.h"

#include "entity_manager.h"

#include "render_system.h"
#include "movement_system.h"

#ifndef ENGINE_H
#define ENGINE_H

class Engine {
	public:
		Engine();

		enum State {
			Stop,
			Gameplay
		};

		void start();
		void stop();
	private:
		Screen scr;
		EntityManager entity_manager;
		RenderSystem render_system = RenderSystem(entity_manager);
		MovementSystem movement_system = MovementSystem(entity_manager);

		State state;

		void process();
		void draw();

};

#endif
