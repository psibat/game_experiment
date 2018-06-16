#include "screen.h"

#include "entity_manager.h"
#include "world.h"

#include "render_system.h"
#include "movement_system.h"
#include "accelerate_system.h"
#include "collision_system.h"

#include "game_state.h"

#ifndef ENGINE_H
#define ENGINE_H

class Engine {
	public:
		Engine();

		void start();
		void stop();
	private:
		GameState state;
		Screen scr;
		EntityManager entity_manager;
		World world;

		// Systems
		RenderSystem render_system;
		AccelerateSystem accelerate_system;
		MovementSystem movement_system;
		CollisionSystem collision_system;

		void gameplay();
		void main_menu();

		void process();
		void draw();

};

#endif
