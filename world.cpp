#include "world.h"

World::World(int height, int width) : height(height), width(width), tiles(height * width) {

};

int World::get_height() {
	return height;
}

int World::get_width() {
	return width;
}

World::Terrain World::get_tile(int y, int x) {
	return tiles.at(width * y + x);
}

World::Terrain World::get_tile(Position position) {
	return tiles.at(width * position.y + position.x);
}

void World::set_tile(int y, int x, Terrain terrain) {
	tiles.at(width * y + x) = terrain;
}

void World::set_tile(Position position, Terrain terrain) {
	tiles.at(width * position.y + position.x) = terrain;
}
