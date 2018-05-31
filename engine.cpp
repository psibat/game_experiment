#include "engine.h"

#include <ncurses.h>

#include "logger.h"
#include "direction.h"
 
Engine::Engine() : world(20, 20),
	render_system(entity_manager, world),
	movement_system(entity_manager, world) {

	}

void Engine::start() {
	int height, width;
	getmaxyx(stdscr, height, width);

	state = GAMEPLAY;

	world.set_tile(10, 10, World::Wall);

	int player = entity_manager.new_entity();
	entity_manager.set_player(player);
	entity_manager.set_center(player);
	entity_manager.set_position(player, new PositionComponent(3, 4));
	entity_manager.set_movement(player, new MovementComponent());
	entity_manager.set_appearance(player, new AppearanceComponent('@'));

	int other = entity_manager.new_entity();
	entity_manager.set_position(other, new PositionComponent(1, 1));
	entity_manager.set_appearance(other, new AppearanceComponent('O'));

	while(state != STOP) {
		draw();
		process();
		log("---!---");
	}
}

void Engine::stop() { state = STOP; }

void Engine::process() {
	int ch = getch();

	int player = entity_manager.get_player();
	entity_manager.get_movement(player)->distance = 1;
	if(ch == KEY_LEFT) {
		entity_manager.get_movement(player)->direction = Direction::EAST;
		log("Left input");
	} else if(ch == KEY_RIGHT) {
		entity_manager.get_movement(player)->direction = Direction::WEST;
		log("Right input");
	} else if(ch == KEY_UP) {
		entity_manager.get_movement(player)->direction = Direction::NORTH;
		log("Up input");
	} else if(ch == KEY_DOWN) {
		entity_manager.get_movement(player)->direction = Direction::SOUTH;
		log("Down input");
	} else if(ch == 'q' || ch == 'Q') {
		stop();
	}

	movement_system.update();
}

void Engine::draw() {
	erase();
	render_system.update();
	refresh();
}
