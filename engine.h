#include "screen.h"

#include "entity_manager.h"
#include "world.h"

#include "render_system.h"
#include "collision_system.h"
#include "movement_system.h"

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
		RenderSystem render_system = RenderSystem(entity_manager, world);
		CollisionSystem collision_system = CollisionSystem(entity_manager, world);
		MovementSystem movement_system = MovementSystem(entity_manager);

		void process();
		void draw();

};

#endif
