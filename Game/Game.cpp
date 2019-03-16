#include "Game.h"
#include "PrimitiveManager.h"
#include "LightManager.h"


Game::Game(HINSTANCE hinstance)
	: Application(hinstance)
{
	auto& testBox = GetECS()->GetEntityManager()->Create();

	auto mesh = GetECS()->GetComponentManager<PrimitiveManager>()->Create(testBox);

	auto sun = std::make_shared<Light>();
	GetSystemManager()->Get<LightSystem>()->Add(sun);
	sun->direction = { -0.2f, -0.9f, 0.1f };
}


Game::~Game()
{
}
