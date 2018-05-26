#include "engine.h"

#include <ncurses.h>

#include "logger.h"
 
Engine::Engine() { }

void Engine::start() {
	int height, width;
	getmaxyx(stdscr, height, width);

	state = Gameplay;

	int player = entity_manager.new_entity();
	entity_manager.set_player(player);
	entity_manager.set_position(player, new PositionComponent(3, 4));
	entity_manager.set_appearance(player, new AppearanceComponent('@'));
	entity_manager.set_movement(player, new MovementComponent(0, 0));

	while(state != Stop) {
		draw();
		process();
	}
}

void Engine::stop() {
	state = Stop;
}

void Engine::process() {
	int player = entity_manager.get_player();
	int ch = getch();
	if(ch == KEY_LEFT) {
		entity_manager.get_movement(player)->x--;
		log("Left input");
	} else if(ch == KEY_RIGHT) {
		entity_manager.get_movement(player)->x++;
		log("Right input");
	} else if(ch == KEY_UP) {
		entity_manager.get_movement(player)->y--;
		log("Up input");
	} else if(ch == KEY_DOWN) {
		entity_manager.get_movement(player)->y++;
		log("Down input");
	} else if(ch == 'q' || ch == 'Q') {
		stop();
	}
	entity_manager.delete_entity(player);

	movement_system.work();
}

void Engine::draw() {
	erase();
	render_system.work();
	refresh();
}
