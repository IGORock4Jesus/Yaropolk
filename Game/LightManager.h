#pragma once

#include <list>
#include <memory>

#include "ComponentManager.h"
#include "Light.h"
#include "Renderer.h"


class LightManager : public BaseComponentManager<Light>
{
	void Render(LPDIRECT3DDEVICE9 device);

public:
};