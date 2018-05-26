#include "component.h"

#ifndef APPEARANCE
#define APPEARANCE

struct Appearance : public Component {
	Appearance(char model);

	char model;

};

#endif
