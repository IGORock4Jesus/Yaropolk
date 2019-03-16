using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using SharpDX;
using SharpDX.Direct3D9;

namespace Yaropolk
{
	//[RequireComponent(typeof(Terrain))]
	class TerrainMesh : Component, IDrawable, IDisposable
	{
		private Terrain terrain;
		VertexBuffer vertexBuffer;
		IndexBuffer indexBuffer;
		private Device device;
		private bool ready;

		public bool Visible { get; set; } = true;
		public float CellSize { get; set; } = 1f;
		public float HeightScale { get; set; } = 1.0f;


		public TerrainMesh(Device device)
		{
			this.device = device;
		}

		protected override void OnInitialize()
		{
			base.OnInitialize();

			terrain = GameObject.GetComponent<Terrain>();

			UpdateMesh();
		}

		private void UpdateMesh()
		{
			if (indexBuffer != null)
				indexBuffer.Dispose();
			if (vertexBuffer != null)
				vertexBuffer.Dispose();

			indexBuffer = new IndexBuffer(device, sizeof(int) * (terrain.Width - 1) * (terrain.Height - 1) * 3, Usage.WriteOnly, Pool.Managed, false);

			vertexBuffer = new VertexBuffer(device, Marshal.SizeOf(typeof(Vertex)) * terrain.Height * terrain.Width, Usage.WriteOnly, VertexFormat.Position | VertexFormat.Diffuse, Pool.Managed);

			using (var data = indexBuffer.Lock(0, 0, LockFlags.None))

				for (int y = 0; y < terrain.Height - 1; y++)
				{
					for (int x = 0; x < terrain.Width - 1; x++)
					{
						data.WriteRange(new int[] {
							y * terrain.Width + x,
							y * terrain.Width + x + 1,
							(y+1) * terrain.Width + x+1,

							y*terrain.Width+x,
							(y+1) *terrain.Width + x + 1,
							(y+1) * terrain.Width + x
						});
					}
				}
			indexBuffer.Unlock();

			using (var data = vertexBuffer.Lock(0, 0, LockFlags.None))
			{
				for (int y = 0; y < terrain.Height; y++)
				{
					for (int x = 0; x < terrain.Width; x++)
					{
						data.Write(new Vertex
						{
							position = new Vector3(x * CellSize, terrain[x, y] * HeightScale, y * CellSize),
							color = BitConverter.ToUInt32(Color.GreenYellow.ToArray(), 0)
						});
					}
				}
			}
			vertexBuffer.Unlock();

			ready = true;
		}

		public void Draw(Device device)
		{
			if (!ready) return;
			device.VertexFormat = VertexFormat.Position | VertexFormat.Diffuse;
			device.SetStreamSource(0, vertexBuffer, 0, Marshal.SizeOf<Vertex>());
			device.Indices = indexBuffer;
			device.DrawIndexedPrimitive(PrimitiveType.TriangleList, 0, 0, terrain.Width * terrain.Height, 0, (terrain.Width - 1) * (terrain.Height - 1) * 2);
		}

		public void Dispose()
		{
			if (indexBuffer != null)
				indexBuffer.Dispose();
			if (vertexBuffer != null)
				vertexBuffer.Dispose();
		}
	}

	class TerrainMeshManager : ComponentManager
	{
		List<TerrainMesh> terrainMeshes = new List<TerrainMesh>();


		public TerrainMeshManager(Renderer renderer)
		{
			renderer.Drawing += Renderer_Drawing;
		}

		internal TerrainMesh Create(GameObject gameObject, Device device)
		{
			TerrainMesh terrainMesh = new TerrainMesh(device);

			gameObject.AddComponent(terrainMesh);

			terrainMeshes.Add(terrainMesh);

			return terrainMesh;
		}

		private void Renderer_Drawing(Device device)
		{
			foreach (var mesh in terrainMeshes)
			{
				mesh.Draw(device);
			}
		}
	}
}
