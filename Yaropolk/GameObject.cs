using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Yaropolk
{
	class GameObject
	{
		public string name;
		readonly List<Component> components = new List<Component>();

		internal T GetComponent<T>() where T : Component
		{
			return components.First(w => w is T) as T;
		}

		internal void AddComponent<T>(T component) where T :Component
		{
			if (HasComponent<T>())
				throw new Exception($"Объект уже содержит {typeof(T).Name} компонент.");

			component.Initialize(this);
			components.Add(component);
		}

		internal bool HasComponent<T>()
		{
			return components.Any(w => w is T);
		}
	}
}
