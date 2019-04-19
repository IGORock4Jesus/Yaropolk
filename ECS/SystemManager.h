#pragma once

#include <memory>
#include <vector>
#include <map>
#include <algorithm>

#include "ECS_API.h"
#include "System.h"

namespace Yaropolk::ECS {

class ECS_API SystemManager
{

	std::map<std::shared_ptr<ISystem>, std::vector<std::shared_ptr<ISystem>>> systems; // системы		
	std::vector<std::shared_ptr<ISystem>> orderedSystems;// отсортированные системы

	//std::map<SystemID, std::map<SystemID, bool>> dependencies; // зависимости систем


	void UpdateOrder();

public:
	SystemManager();
	~SystemManager();

	// ƒобавл€ет систему.
	template <typename T, typename ...TArgs>
	std::shared_ptr<T> Add(TArgs&& ... args) {
		auto s = std::make_shared<T>(std::forward<TArgs>(args)...);
		systems[s] = {};
		return s;
	}

	template <typename T>
	std::shared_ptr<T> Get() const {
		auto t = std::find_if(orderedSystems.begin(), orderedSystems.end(), [](auto && s) { return s->ID == T::ID; });
		if (t == orderedSystems.end())
			return nullptr;
		else
			return *t;
	}

	// ѕодсчитывает количество систем.
	size_t Count() const { return orderedSystems.size(); }

	template <typename T, typename D>
	void AddDependency(std::shared_ptr<T> target, std::shared_ptr<D> dependency) {
		static_assert(std::is_base_of_v<ISystem, T>, "T должен быть унаследован от ISystem интерфейса.");
		static_assert(std::is_base_of_v<ISystem, D>, "D должен быть унаследован от ISystem интерфейса.");

		systems[target].push_back(dependency);
	}

	bool Initialize();

	template <typename T>
	size_t GetIndex() const {
		for (size_t i = 0; i < orderedSystems.size(); i++)
		{
			if (orderedSystems[i]->GetID() == T::ID)
				return i;
		}
		return -1;
	}
};

}