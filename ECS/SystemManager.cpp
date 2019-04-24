#include "SystemManager.h"


namespace Yaropolk::ECS {

//static void OrderSort(std::map<std::shared_ptr<ISystem>, std::vector<std::shared_ptr<ISystem>>>& map,
//	std::map<SystemID, std::shared_ptr<ISystem>>& ordered,
//	const std::pair<std::shared_ptr<ISystem>, std::vector<std::shared_ptr<ISystem>>>& s = {}) {
//	for (auto&& s : s.second) {
//		for (auto&& m : map) {
//			if (m.first == s) {
//				OrderSort(map, ordered, m);
//			}
//		}
//	}
//
//	auto it = std::find(ordered.begin(), ordered.end(), s.first);
//	if (it == ordered.end())
//		ordered.insert({ s.first->GetID(), s.first });
//}

void SystemManager::UpdateOrder()
{
	//orderedSystems.clear();

	/*for (auto&& s : systems)
		OrderSort(systems, orderedSystems, s);*/
}

void SystemManager::Update(float elapsedTime)
{
	for (auto&& s : systems) {
		s.second->Update(elapsedTime);
	}
}

SystemManager::SystemManager()
{
	thread.Updating.Add(this, &SystemManager::Update);
	thread.SetDelay(5);
}


SystemManager::~SystemManager()
{
}

bool SystemManager::Initialize()
{
	UpdateOrder();

	for (auto&& s : systems) {
		if (!s.second->Initialize(this)) {
			return false;
		}
	}

	return true;
}

bool SystemManager::Start()
{
	thread.Start();
	return true;
}

void SystemManager::Stop()
{
	thread.Stop();
}

}