using SharpDX;
using SharpDX.Direct3D9;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Yaropolk
{
	class Renderer:IDisposable
	{
		Direct3D direct;
		Device device;
		private bool enabled;

		public Device Device => device;

		public delegate void DeviceHandler(Device device);
		public event DeviceHandler Drawing;


		public Renderer(Form form)
		{
			direct = new Direct3D();
			device = new Device(direct, 0, DeviceType.Hardware, form.Handle, CreateFlags.HardwareVertexProcessing | CreateFlags.Multithreaded, new PresentParameters
			{
				AutoDepthStencilFormat = Format.D24S8,
				BackBufferCount = 1,
				BackBufferFormat = Format.X8R8G8B8,
				BackBufferHeight = form.ClientSize.Height,
				BackBufferWidth = form.ClientSize.Width,
				DeviceWindowHandle = form.Handle,
				EnableAutoDepthStencil = true,
				SwapEffect = SwapEffect.Discard,
				Windowed = true
			});

			device.SetRenderState(RenderState.Lighting, false);

			enabled = true;
			Task.Run(new Action(Start));
		}

		public void Dispose()
		{
			enabled = false;
			device.Dispose();
			direct.Dispose();
		}

		private void Start()
		{
			while (enabled)
			{
				device.Clear(ClearFlags.All, Color.Gray, 1.0f, 0);
				device.BeginScene();

				device.SetTransform(TransformState.Projection, Matrix.PerspectiveFovLH(MathUtil.PiOverFour, 1.0f, 0.1f, 10000.0f));
				device.SetTransform(TransformState.View, Matrix.LookAtLH(new Vector3(0.0f, 20.0f, -20.0f), new Vector3(0.0f), new Vector3(0.0f, 1.0f, 0.0f)));

				Drawing?.Invoke(device);

				device.EndScene();
				device.Present();
			}
		}
	}
}
