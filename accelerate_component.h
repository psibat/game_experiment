#include "component.h"

#include "direction.h"

#ifndef ACCELERATE_COMPONENT_H
#define ACCELERATE_COMPONENT_H

struct AccelerateComponent : public Component {
		AccelerateComponent();
		Direction direction;
		int distance;
		int speed;

};

#endif
