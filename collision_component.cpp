#include "collision_component.h"
 
CollisionComponent::CollisionComponent(bool tangible, std::set<World::Terrain> passable_terrain) :
	tangible(tangible),
	passable_terrain(passable_terrain) {

	}
