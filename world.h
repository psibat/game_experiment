#include <vector>

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

	private:
		int height;
		int width;

		std::vector<Terrain> tiles;
};

#endif
