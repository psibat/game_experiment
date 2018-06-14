#include <vector>
#include <map>

#include "position_component.h"
#include "movement_component.h"
#include "appearance_component.h"
#include "accelerate_component.h"
#include "collision_component.h"

#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

static const int MAX_ENTITIES = 200;

class EntityManager {
	public:
		EntityManager();

		int create();
		void destroy(int id);
		bool exists(int id);
		
		void add(int id, Component *component);

		template <typename T> T
			*get(int id) {
				return static_cast<T*>(components.at(&typeid(T)).at(id));
			}

		template <typename T>
			void remove(int id) {
				const std::type_info *type = &typeid(T);
				delete components.at(type).at(id);
				components.at(type).at(id) = NULL;
			}

		// Single owner entity flags
		int player = -1;
		int center = -1;

	private:
		// Components / flags
		std::vector<bool> existence;

		typedef std::vector<Component *> ComponentVector;
		std::map<const std::type_info*, ComponentVector> components {
			{&typeid(PositionComponent), ComponentVector(MAX_ENTITIES)},
			{&typeid(MovementComponent), ComponentVector(MAX_ENTITIES)},
			{&typeid(AppearanceComponent), ComponentVector(MAX_ENTITIES)},
			{&typeid(AccelerateComponent), ComponentVector(MAX_ENTITIES)},
			{&typeid(CollisionComponent), ComponentVector(MAX_ENTITIES)}
		};

};

#endif
