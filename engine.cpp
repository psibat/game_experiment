#include "engine.h"

#include <ncurses.h>

#include "logger.h"
 
Engine::Engine() { }

void Engine::start() {
	int height, width;
	getmaxyx(stdscr, height, width);

	state = Gameplay;

	int id = entity_manager.new_entity();
	entity_manager.set_position(id, new PositionComponent(3, 4));
	entity_manager.set_appearance(id, new AppearanceComponent('@'));

	while(state != Stop) {
		draw();
		process();
	}
}

void Engine::stop() {
	state = Stop;
}

void Engine::process() {
	int ch = getch();
	if(ch == KEY_LEFT) {
		log("Left input");
	} else if(ch == KEY_RIGHT) {
		log("Right input");
	} else if(ch == KEY_UP) {
		log("Up input");
	} else if(ch == KEY_DOWN) {
		log("Down input");
	} else if(ch == 'q' || ch == 'Q') {
		stop();
	}
}

void Engine::draw() {
	erase();
	render_system.work();
	refresh();
}
