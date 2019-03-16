#pragma once

#include <list>
#include <memory>
#include <mutex>


template <typename ...TArgs>
class Event
{
	enum class Type
	{
		Class,
		Static
	};

	struct Delegate
	{
		Type type;
		virtual void Process(TArgs ... args) = 0;
	};

	template <typename TClass, typename TMethod>
	struct ClassDelegate : Delegate
	{
		TClass* object;
		TMethod method;

		ClassDelegate(TClass* object, TMethod method)
			: object{ object }, method{ method }
		{
		}

		void Process(TArgs ... args) override
		{
			(object->*method)(args...);
		}
	};

	template <typename TFunc>
	struct StaticDelegate : Delegate
	{
		TFunc func;

		StaticDelegate(TFunc func)
			: func{ func }
		{
		}

		void Process(TArgs ... args) override
		{
			func(args...);
		}
	};

	std::list<std::shared_ptr<Delegate>> delegates;
	std::mutex mutex;

public:
	template <typename TClass, typename TMethod>
	void Add(TClass* object, TMethod method)
	{
		if (!object)
			throw std::exception("Параметр \"object\" пустой.");
		if (!method)
			throw std::exception("Параметр \"method\" пустой.");

		auto item = std::make_shared<ClassDelegate<TClass, TMethod>>(object, method);
		std::lock_guard<std::mutex> locker{ mutex };
		delegates.push_back(item);
	}

	template <typename TFunc>
	void Add(TFunc func)
	{
		if (!func)
			throw std::exception("Параметр \"func\" пустой.");
		std::lock_guard<std::mutex> locker{ mutex };
		delegates.push_back(std::make_shared<StaticDelegate<TFunc>>(func));
	}

	template <typename TClass, typename TMethod>
	void Remove(TClass* object, TMethod method)
	{
		std::lock_guard<std::mutex> locker{ mutex };
		delegates.remove_if([&](auto del)
		{
			return del->object == object && del->method == method;
		});
	}

	template <typename TFunc>
	void Remove(TFunc func)
	{
		std::lock_guard<std::mutex> locker{ mutex };
		delegates.remove_if([&](auto del)
		{
			return del->func == func;
		});
	}

	void operator()(TArgs ... args)
	{
		std::lock_guard<std::mutex> locker{ mutex };
		for (auto&& del : delegates)
		{
			del->Process(args...);
		}
	}
};
