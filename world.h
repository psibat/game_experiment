#include <vector>
#include "position.h"

#ifndef WORLD_H
#define WORLD_H

class World {
	public:
		World(int y, int x);

		enum Terrain {
			None,
			Wall
		};

		int get_height();
		int get_width();

		Terrain get_tile(int y, int x);
		Terrain get_tile(Position position);
		void set_tile(int y, int x, Terrain terrain);
		void set_tile(Position position, Terrain terrain);

	private:
		int height;
		int width;

		std::vector<Terrain> tiles;
};

#endif
