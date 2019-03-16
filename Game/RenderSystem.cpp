#include "RenderSystem.h"
#include "ECS.h"
#include "LightManager.h"
#include "PrimitiveManager.h"


void RenderSystem::Render(LPDIRECT3DDEVICE9 device)
{
	std::list<std::shared_ptr<IRenderable>> list;

	auto& lights = GetECS()->GetComponentManager<LightManager>()->GetArray();
	list.insert(list.end(), lights.begin(), lights.end());

	auto& primitives = GetECS()->GetComponentManager<PrimitiveManager>()->GetArray();
	list.insert(list.end(), primitives.begin(), primitives.end());

	for (auto&& l : list) {
		l->Render(device);
	}
}

RenderSystem::RenderSystem(std::shared_ptr<Renderer> renderer)
{
	renderer->Drawing.Add(this, &RenderSystem::Render);
}
