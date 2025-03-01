#include "Cursol.h"

using namespace MakeMatrix;

Cursol::Cursol() : Object({4, 4}) {
	color_ = 0xffffffff;
}

Vector2 Cursol::GetCursolPos(Camera& camera) {
	int x = 0;
	int y = 0;

	Novice::GetMousePosition(&x, &y);
	return Vector2(static_cast<float>(x), static_cast<float>(y)) * Inverse(camera.GetMatrix());
}

void Cursol::Update(Camera& camera) {
	pos_ = GetCursolPos(camera);

	Ready(camera, 255);
}
