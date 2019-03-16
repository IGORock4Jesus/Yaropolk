#pragma once

#include <d3d9.h>
#include <list>
#include <memory>
#include "Primitive.h"
#include "Renderer.h"
#include "ComponentManager.h"


class PrimitiveManager : public BaseComponentManager<Primitive>
{
};

