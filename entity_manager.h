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

		void set_player(int id);
		int get_player();

		void set_center(int id);
		int get_center();

		void add(int id, Component *component) {
			components.at(&typeid(*component)).at(id) = component;
		}

		template <typename T> T *get(int id) {
			return static_cast<T*>(components.at(&typeid(T)).at(id));
		}

	private:
		// Single owner entity flags
		int player = -1;
		int center = -1;
		
		// Components / flags
		std::vector<bool> existence;

		std::map<const std::type_info*, std::vector<Component *>> components {
			{&typeid(PositionComponent), std::vector<Component *>(MAX_ENTITIES)},
			{&typeid(MovementComponent), std::vector<Component *>(MAX_ENTITIES)},
			{&typeid(AppearanceComponent), std::vector<Component *>(MAX_ENTITIES)},
			{&typeid(AccelerateComponent), std::vector<Component *>(MAX_ENTITIES)},
			{&typeid(CollisionComponent), std::vector<Component *>(MAX_ENTITIES)}
		};

};

#endif
