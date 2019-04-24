#pragma once

#include <string>
#include "GraphicsAPI.h"

namespace Yaropolk::Graphics {

__interface GRAPHICS_API IRenderer
{
	void Begin();
	void End();

	void DrawRectangle(float x, float y, float w, float h, DWORD argb);
	void DrawString(float x, float y, float w, float h, int fontSize, std::string text, std::string fontName, DWORD format = DT_LEFT | DT_TOP);
};

}

