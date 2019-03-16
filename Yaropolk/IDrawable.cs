using SharpDX.Direct3D9;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Yaropolk
{
	interface IDrawable
	{
		bool Visible { get; set; }
		void Draw(Device device);
	}
}
