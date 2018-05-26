#include "engine.h"

#include <ncurses.h>

#include "logger.h"
 
Engine::Engine() : world(0, 0) { }

void Engine::start() {
	int height, width;
	getmaxyx(stdscr, height, width);

	state = GAMEPLAY;

	int player = entity_manager.new_entity();
	entity_manager.set_player(player);
	entity_manager.set_center(player);
	entity_manager.set_position(player, new PositionComponent(3, 4));
	entity_manager.set_appearance(player, new AppearanceComponent('@'));
	entity_manager.set_movement(player, new MovementComponent(0, 0));

	int other = entity_manager.new_entity();
	entity_manager.set_position(other, new PositionComponent(1, 1));
	entity_manager.set_appearance(other, new AppearanceComponent('O'));

	while(state != STOP) {
		draw();
		process();
		world = World(12, 40);
		world.set_tile(10, 10, World::Wall);
	}
}

void Engine::stop() {
	state = STOP;
}

void Engine::process() {
	int ch = getch();

	int player = entity_manager.get_player();
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
	movement_system.work();
}

void Engine::draw() {
	erase();
	render_system.work();
	refresh();
}
