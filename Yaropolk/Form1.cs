using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Yaropolk
{
	public partial class Form1 : Form
	{
		Renderer renderer;
		Scene scene;
		SystemManager systemManager;

		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			renderer = new Renderer(this);
			scene = new Scene();
			systemManager = new SystemManager(renderer);

			var gameObject = new GameObject();
			var terrain = systemManager.GetManager<TerrainManager>().Create(gameObject, 10, 10, null);
			var terrainMesh = systemManager.GetManager<TerrainMeshManager>().Create(gameObject, renderer.Device);

			scene.AddObject(gameObject);
		}

		private void Form1_FormClosed(object sender, FormClosedEventArgs e)
		{
			renderer.Dispose();
		}
	}
}
