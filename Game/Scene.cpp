#include "Scene.h"



Scene::Scene(std::shared_ptr<Renderer> renderer)
{
	renderer->Drawing.Add(this, &Scene::Render);
}


Scene::~Scene()
{
}

void Scene::Update(float time)
{
}

void Scene::Render(LPDIRECT3DDEVICE9 device)
{
	for (auto&& o : objects) {
		o->Render(device);
	}
}
