using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Yaropolk
{
	class Terrain : Component
	{
		float[,] heightMap;

		public Terrain(int width, int height, string filename)
		{
			heightMap = new float[width, height];
			Width = width;
			Height = height;
		}

		public int Height { get; }
		public int Width { get; }

		public float this[int x, int y]
		{
			get => heightMap[x, y];
		}
	}

	class TerrainManager : ComponentManager
	{
		List<Terrain> terrains = new List<Terrain>();

		public Terrain Create(GameObject gameObject, int width, int height, string filename)
		{
			if (gameObject.HasComponent<Terrain>())
				throw new Exception("Объект уже содежит компонент Terrain.");

			Terrain terrain = new Terrain(width, height, filename);
			gameObject.AddComponent(terrain);
			terrains.Add(terrain);

			return terrain;
		}
	}
}
