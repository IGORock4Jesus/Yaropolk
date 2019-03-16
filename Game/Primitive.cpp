#include "Primitive.h"
#include "Vertex.h"


void BoxMesh::Render(LPDIRECT3DDEVICE9 device) {
	auto half = size / 2.0f;
	ColorVertex vertices[]{
		// bottom
		{{-half.x, -half.y, -half.z}, {0.0f, -1.0f, 0.0f}, color},
		{{ half.x, -half.y, -half.z}, {0.0f, -1.0f, 0.0f}, color},
		{{ half.x, -half.y,  half.z}, {0.0f, -1.0f, 0.0f}, color},
		{{-half.x, -half.y,  half.z}, {0.0f, -1.0f, 0.0f}, color},
		// top
		{{-half.x,  half.y, -half.z}, {0.0f, 1.0f, 0.0f}, color},
		{{ half.x,  half.y, -half.z}, {0.0f, 1.0f, 0.0f}, color},
		{{ half.x,  half.y,  half.z}, {0.0f, 1.0f, 0.0f}, color},
		{{-half.x,  half.y,  half.z}, {0.0f, 1.0f, 0.0f}, color},
		// front
		{{-half.x, -half.y, -half.z}, {0.0f, 0.0f, -1.0f}, color},
		{{-half.x,  half.y, -half.z}, {0.0f, 0.0f, -1.0f}, color},
		{{ half.x,  half.y, -half.z}, {0.0f, 0.0f, -1.0f}, color},
		{{ half.x, -half.y, -half.z}, {0.0f, 0.0f, -1.0f}, color},
		// back
		{{ half.x, -half.y,  half.z}, {0.0f, 0.0f, 1.0f}, color},
		{{ half.x,  half.y,  half.z}, {0.0f, 0.0f, 1.0f}, color},
		{{-half.x,  half.y,  half.z}, {0.0f, 0.0f, 1.0f}, color},
		{{-half.x, -half.y,  half.z}, {0.0f, 0.0f, 1.0f}, color},
		// right
		{{ half.x, -half.y, -half.z}, {1.0f, 0.0f, 0.0f}, color},
		{{ half.x,  half.y, -half.z}, {1.0f, 0.0f, 0.0f}, color},
		{{ half.x,  half.y,  half.z}, {1.0f, 0.0f, 0.0f}, color},
		{{ half.x, -half.y,  half.z}, {1.0f, 0.0f, 0.0f}, color},
		// left
		{{-half.x, -half.y,  half.z}, {-1.0f, 0.0f, 0.0f}, color},
		{{-half.x,  half.y,  half.z}, {-1.0f, 0.0f, 0.0f}, color},
		{{-half.x,  half.y, -half.z}, {-1.0f, 0.0f, 0.0f}, color},
		{{-half.x, -half.y, -half.z}, {-1.0f, 0.0f, 0.0f}, color},
	};

	USHORT indices[]{
		0, 1, 2,
		0, 2, 3,

		4, 7, 6,
		4, 6, 5,

		8, 9, 10,
		8, 10, 11,

		12, 15, 14,
		12, 14, 13,

		16, 17, 18,
		16, 18, 19,

		20, 23, 22,
		20, 22, 21
	};

	device->SetFVF(ColorVertex::format);
	device->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, 24, 10, indices, D3DFMT_INDEX16, vertices, ColorVertex::size);
}
