#pragma once

#include "System.h"
#include "IRenderable.h"
#include "Renderer.h"


class RenderSystem : public System {
	void Render(LPDIRECT3DDEVICE9 device);

public:
	RenderSystem(std::shared_ptr<Renderer> renderer);
};