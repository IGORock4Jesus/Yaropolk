#pragma once

#include <memory>
#include <ECS/System.h>
#include <ECS/Engine.h>
#include <Subsystem/Window.h>


namespace Yaropolk::Tetris
{

class InputSystem : public ECS::System<InputSystem> {
	std::shared_ptr<ECS::Engine> ecs;

	void KeyDown(int key);
public:
	InputSystem(std::shared_ptr<ECS::Engine> ecs, std::shared_ptr<Subsystem::Window> window);

};

}