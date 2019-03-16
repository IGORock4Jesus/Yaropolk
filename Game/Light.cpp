#include "Light.h"

void Light::Render(LPDIRECT3DDEVICE9 device)
{
	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(light));
	light.Ambient = { 0.2f, 0.2f, 0.2, 1.0f };
	light.Diffuse = color;
	D3DXVec3Normalize(&direction, &direction);
	light.Direction = direction;
	light.Type = D3DLIGHTTYPE::D3DLIGHT_DIRECTIONAL;

	device->SetLight(0, &light);
	device->LightEnable(0, TRUE);
}
