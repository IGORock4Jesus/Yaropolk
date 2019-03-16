#pragma once

#include <memory>
#include "Component.h"

class ECS;

class System {
	ECS *ecs;

protected:
	ECS *GetECS() const { return ecs; }

public:
	virtual ~System() {}
};

