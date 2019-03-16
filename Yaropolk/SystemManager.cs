using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Yaropolk
{
	class SystemManager
	{
		readonly List<ComponentManager> managers;

		public SystemManager(Renderer renderer)
		{
			managers = new List<ComponentManager>
			{
				new TerrainManager(),
				new TerrainMeshManager(renderer)
			};
		}

		internal T GetManager<T>() where T : ComponentManager
		{
			return managers.First(w => w is T) as T;
		}
	}
}
