#pragma once

#include <memory>
#include <list>
#include <algorithm>

namespace Yaropolk::Trivial
{

template <typename ..._Args>
class Event {

	enum class Type
	{
		Static,
		Object
	};

	struct IItem
	{
		virtual Type GetType() = 0;
		virtual void Process(_Args ... args) = 0;
	};

	template <typename _Func>
	struct StaticItem : IItem {
		_Func func;
		StaticItem(_Func func) :func{ func } {}
		Type GetType() override {
			return Type::Static;
		}
		void Process(_Args ... args) override {
			func(args...);
		}
	};

	template <typename _Class, typename _Method>
	struct ObjectItem : IItem
	{
		_Class* object;
		_Method method;
		ObjectItem(_Class* object, _Method method) : object{ object }, method{ method }{}
		Type GetType() override {
			return Type::Object;
		}
		void Process(_Args ... args) override {
			(object->*method)(args...);
		}
	};

	std::list<std::shared_ptr<IItem>> items;

public:
	template <typename _Func>
	void Add(_Func func) {
		items.push_back(std::make_shared<StaticItem<_Func>>(func));
	}

	template <typename _Class, typename _Method>
	void Add(_Class* object, _Method method) {
		items.push_back(std::make_shared<ObjectItem<_Class, _Method>>(object, method));
	}

	template <typename _Func>
	void Remove(_Func func) {
		std::remove_if(items.begin(), items.end(), [&](const std::shared_ptr<IItem> & item) {
			if (item->GetType() == Type::Static) {
				auto p = std::dynamic_pointer_cast<StaticItem<_Func>>(item);
				if (p->func == func) {
					return true;
				}
			}
			return false;
		});
	}

	template <typename _Class, typename _Method>
	void Remove(_Class* object, _Method method) {
		std::remove_if(items.begin(), items.end(), [&](const std::shared_ptr<IItem> & item) {
			if (item->GetType() == Type::Object) {
				auto p = std::dynamic_pointer_cast<ObjectItem<_Class, _Method>>(item);
				if (p->object == object && p->method == method) {
					return true;
				}
			}
			return false;
		});
	}

	void operator () (_Args ...args) {
		for (auto&& p : items) {
			p->Process(args...);
		}
	}
};

}
