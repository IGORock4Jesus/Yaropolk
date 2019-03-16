#pragma once

#include <d3dx9.h>


struct Transform
{
	D3DXVECTOR3 position{ 0.0f, 0.0f, 0.0f };
	D3DXVECTOR3	scale{ 1.0f, 1.0f, 1.0f };
	D3DXQUATERNION rotation;

	Transform()
	{
		D3DXQuaternionIdentity(&rotation);
	}

	const D3DXMATRIX &ToMatrix() const {
		D3DXMATRIX t, r, s;
		D3DXMatrixTranslation(&t, position.x, position.y, position.z);
		D3DXMatrixScaling(&s, scale.x, scale.y, scale.z);
		D3DXMatrixRotationQuaternion(&r, &rotation);
		return s * r * t;
	}
};