#include "SystemManager.h"


namespace Yaropolk::ECS {

static void OrderSort(std::map<std::shared_ptr<ISystem>, std::vector<std::shared_ptr<ISystem>>>& map,
	std::vector<std::shared_ptr<ISystem>>& ordered,
	const std::pair<std::shared_ptr<ISystem>, std::vector<std::shared_ptr<ISystem>>>& s = {}) {
	for (auto&& s : s.second) {
		for (auto&& m : map) {
			if (m.first == s) {
				OrderSort(map, ordered, m);
			}
		}
	}

	auto it = std::find(ordered.begin(), ordered.end(), s.first);
	if (it == ordered.end())
		ordered.push_back(s.first);
}

void SystemManager::UpdateOrder()
{
	orderedSystems.clear();

	for (auto&& s : systems)
		OrderSort(systems, orderedSystems, s);
}

SystemManager::SystemManager()
{
}


SystemManager::~SystemManager()
{
}

bool SystemManager::Initialize()
{
	UpdateOrder();

	for (auto&& s : orderedSystems) {
		if (!s->Initialize(this)) {
			return false;
		}
	}

	return true;
}

}