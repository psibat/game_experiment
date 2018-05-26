#include "component.h"

#ifndef APPEARANCE_COMPONENT_H
#define APPEARANCE_COMPONENT_H

struct AppearanceComponent : public Component {
	AppearanceComponent(char model);

	char model;
};

#endif
