#pragma once

#include <list>
#include <memory>
#include "Renderer.h"

#include "Entity.h"


class Scene
{
	std::list<std::shared_ptr<Entity>> objects;

	void Render(LPDIRECT3DDEVICE9 device);
public:
	Scene(std::shared_ptr<Renderer> renderer);
	~Scene();

	void Update(float time);
};

