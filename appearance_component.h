#include "component.h"

#ifndef APPEARANCE_COMPONENT
#define APPEARANCE_COMPONENT

struct AppearanceComponent : public Component {
	AppearanceComponent(char model);

	char model;

};

#endif
