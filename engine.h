#include "screen.h"
#include "entity_manager.h"
#include "render_system.h"

#ifndef ENGINE
#define ENGINE

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

		State state;

		void process();
		void draw();

};

#endif
