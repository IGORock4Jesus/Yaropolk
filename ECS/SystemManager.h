#pragma once

#include <memory>
#include <vector>
#include <map>
#include <algorithm>

#include <Trivial/Thread.h>

#include "EcsAPI.h"
#include "System.h"

namespace Yaropolk::ECS {

class ECS_API SystemManager
{

	//std::map<std::shared_ptr<ISystem>, std::vector<std::shared_ptr<ISystem>>> systems; // системы		
	std::map<SystemID, std::shared_ptr<ISystem>> systems;// отсортированные системы
	//std::map<SystemID, std::shared_ptr<ISystem>> orderedSystems;// отсортированные системы

	//std::map<SystemID, std::map<SystemID, bool>> dependencies; // зависимости систем
	Trivial::Thread thread;

	void UpdateOrder();
	void Update(float elapsedTime);

public:
	SystemManager();
	~SystemManager();

	// Добавляет систему.
	template <typename T, typename ...TArgs>
	std::shared_ptr<T> Add(TArgs&& ... args) {
		auto s = std::make_shared<T>(std::forward<TArgs>(args)...);
		//systems[s] = {};
		systems[T::ID] = s;
		return s;
	}

	template <typename T>
	std::shared_ptr<T> Get() const {
		auto t = std::find_if(systems.begin(), systems.end(), [](auto && s) { return s.first == T::ID; });
		if (t == systems.end())
			return nullptr;
		else
			return std::dynamic_pointer_cast<T>(t->second);
	}

	// Подсчитывает количество систем.
	size_t Count() const { return systems.size(); }

	template <typename T, typename D>
	void AddDependency(std::shared_ptr<T> target, std::shared_ptr<D> dependency) {
		static_assert(std::is_base_of_v<ISystem, T>, "T должен быть унаследован от ISystem интерфейса.");
		static_assert(std::is_base_of_v<ISystem, D>, "D должен быть унаследован от ISystem интерфейса.");

		systems[target].push_back(dependency);
	}

	bool Initialize();

	/*template <typename T>
	size_t GetIndex() const {
		for (size_t i = 0; i < orderedSystems.size(); i++)
		{
			if (orderedSystems[i]->GetID() == T::ID)
				return i;
		}
		return -1;
	}*/

	bool Start();
	void Stop();
};

}