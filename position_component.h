#include "position.h"
#include "component.h"

#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

struct PositionComponent : public Position, public Component {
	PositionComponent(int y, int x);
};


#endif
