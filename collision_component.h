#include "component.h"

#include <set>
#include <map>

#include "world.h"

#ifndef COLLISION_COMPONENT_H
#define COLLISION_COMPONENT_H

struct CollisionComponent : public Component {
		CollisionComponent(bool tangible = true,
				std::set<World::Terrain> passable_terrain = {World::None});

		bool tangible;
		std::set<World::Terrain> passable_terrain;
		std::map<int, int> collided_with;
};

#endif
