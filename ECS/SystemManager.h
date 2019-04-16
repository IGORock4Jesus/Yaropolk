#pragma once

#include <memory>
#include <vector>
#include <map>

#include "ECS_API.h"
#include "System.h"

namespace Yaropolk::ECS {

class ECS_API SystemManager
{

	std::vector<std::shared_ptr<ISystem>> systems; // системы		
	std::vector<std::shared_ptr<ISystem>> orderedSystems;// отсортированные системы

	std::map<SystemID, std::map<SystemID, bool>> dependencies; // зависимости систем


	void UpdateOrder();

public:
	SystemManager();
	~SystemManager();

	// ƒобавл€ет систему.
	template <typename T, typename ...TArgs>
	std::shared_ptr<T> Add(TArgs&& ... args) {
		auto s = std::make_shared<T>(std::forward<TArgs>(args)...);
		systems.push_back(s);
		return s;
	}

	// ѕодсчитывает количество систем.
	size_t Count() const { return orderedSystems.size(); }

	template <typename T, typename D>
	void AddDependency(std::shared_ptr<T> target, std::shared_ptr<D> dependency) {
		static_assert(std::is_base_of_v<ISystem, T>, "T должен быть унаследован от ISystem интерфейса.");
		static_assert(std::is_base_of_v<ISystem, D>, "D должен быть унаследован от ISystem интерфейса.");

		dependencies[T::ID][D::ID] = true;
	}

	/*template <typename T, typename D, typename...DS>
	void AddDependency()*/

	void Initialize();
};

}