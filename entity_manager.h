#include <vector>
#include <map>

#include "position_component.h"
#include "movement_component.h"
#include "appearance_component.h"
#include "collision_component.h"

#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

static const int MAX_ENTITIES = 200;

class EntityManager {
	public:
		EntityManager();

		// Entity
		int create();
		void destroy(int id);
		bool exists(int id);

		// Components
		void add(int id, Component *component);
		Component *get(int id, const std::type_info *type);
		void remove(int id, const std::type_info *type);

		template <typename T> T
			*get(int id) {
				return static_cast<T*>(get(id, &typeid(T)));
			}

		template <typename T>
			void remove(int id) {
				remove(id, &typeid(T));
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
			{&typeid(CollisionComponent), ComponentVector(MAX_ENTITIES)}
		};

};

#endif
