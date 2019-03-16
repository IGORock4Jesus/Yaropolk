using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Yaropolk
{
	class Scene
	{
		readonly List<GameObject> gameObjects = new List<GameObject>();

		internal void AddObject(GameObject gameObject)
		{
			if (gameObjects.Contains(gameObject))
				throw new Exception("Нельзя на сцену добавить один объект два раза.");
			gameObjects.Add(gameObject);
		}
	}
}
