#include "engine.h"

#include <ncurses.h>

#include "logger.h"
 
Engine::Engine() { }

void Engine::start() {
	int height, width;
	getmaxyx(stdscr, height, width);

	running = true;

	entity_manager.createMan(3, 5);
	entity_manager.createMan(7, 10);
	entity_manager.createMan(5, 54);

	while(running) {
		draw();
		process();
	}
}

void Engine::stop() {
	running = false;
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
	entity_manager.render();
	refresh();
}
