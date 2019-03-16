#pragma once

#include <memory>
#include <string>
#include "Event.h"


class Entity;

class Component {
	friend Entity;

	Entity* entity{ nullptr };
	bool enabled{ false };

	/*void Initialize(Entity *entity) {
		this->entity = entity;
		enabled = true;

		Created(this, entity);
	}*/
public:
	Event<const Component*, const Entity*> Created;


	virtual ~Component() {}

	void SetEnabled(bool value) { enabled = value; }
	bool GetEnabled() const { return enabled; }
};
