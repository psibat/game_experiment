#include "engine.h"

#include <ncurses.h>

#include "logger.h"
#include "direction.h"
 
Engine::Engine() : world(20, 20),
	render_system(entity_manager, world),
	accelerate_system(entity_manager, world),
	movement_system(entity_manager, world),
	collision_system(entity_manager, world) {

	}

void Engine::start() {
	int height, width;
	getmaxyx(stdscr, height, width);

	state = GAMEPLAY;

	world.set_tile(19, 19, World::Wall);

	int player = entity_manager.create();
	entity_manager.player = player;
	entity_manager.center = player;
	entity_manager.add(player, new PositionComponent(3, 4));
	entity_manager.add(player, new MovementComponent());
	entity_manager.add(player, new AppearanceComponent('@'));
	entity_manager.add(player, new CollisionComponent(true));

	int other = entity_manager.create();
	entity_manager.add(other, new PositionComponent(1, 1));
	entity_manager.add(other, new AppearanceComponent('O'));
	entity_manager.add(other, new CollisionComponent(true));

	while(state != STOP) {
		draw();
		process();
		log("---!---");
	}
}

void Engine::stop() {
	state = STOP;
}

void Engine::process() {
	int ch = getch();

	int player = entity_manager.player;
	entity_manager.add(player, new AccelerateComponent());
	entity_manager.get<AccelerateComponent>(player)->distance = 1;
	entity_manager.get<AccelerateComponent>(player)->speed = 1;
	if(ch == KEY_LEFT) {
		entity_manager.get<AccelerateComponent>(player)->direction = Direction::EAST;
		log("Left input");
	} else if(ch == KEY_RIGHT) {
		entity_manager.get<AccelerateComponent>(player)->direction = Direction::WEST;
		log("Right input");
	} else if(ch == KEY_UP) {
		entity_manager.get<AccelerateComponent>(player)->direction = Direction::NORTH;
		log("Up input");
	} else if(ch == KEY_DOWN) {
		entity_manager.get<AccelerateComponent>(player)->direction = Direction::SOUTH;
		log("Down input");
	} else if(ch == 'q' || ch == 'Q') {
		stop();
	} else if(ch == ' ') {
		entity_manager.remove<AccelerateComponent>(player);
	}

	accelerate_system.update();
	movement_system.update();
	collision_system.update();

}

void Engine::draw() {
	erase();
	render_system.update();
	refresh();
}
