#include "Cursol.h"

using namespace MakeMatrix;

Cursol::Cursol() : Object({4, 4}) {
	color_ = 0xff;
}

void Cursol::Update(Camera& camera) {
	int x = 0;
	int y = 0;

	Novice::GetMousePosition(&x, &y);
	pos_ = Vector2(static_cast<float>(x), static_cast<float>(y)) * Inverse(camera.GetMatrix());

	Ready(camera, 255);
}
