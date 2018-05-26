#include "screen.h"
#include "entity_manager.h"

#ifndef ENGINE
#define ENGINE

class Engine {
	public:
		Engine();

		void start();
		void stop();
	private:
		Screen scr;
		EntityManager entity_manager;

		bool running;

		void process();
		void draw();

};

#endif
