#include "Polygon.h"
#include "Camera.h"
#include <cmath>

using namespace MakeMatrix;

unsigned int Polygon::AdjustColor(int bright) {
	int alpha = color_ & 0xff;
	color_ >>= 8;

	int blue = color_ & 0xff;
	color_ >>= 8;

	int green = color_ & 0xff;
	color_ >>= 8;

	int red = color_;

	float ratio = bright_ / 255.0f;

	if (isBlackout_) {
		ratio *= bright / 255.0f;
	}

	return static_cast<int>(roundf(alpha)) | (static_cast<int>(roundf(red * ratio)) << 24) | (static_cast<int>(roundf(green * ratio)) << 16) | static_cast<int>(roundf(blue * ratio)) << 8;
}

void Polygon::MakeAffineMatrix(const Camera& camera) {
	matrix_ = MakeScaleMatrix(scale_) * MakeRotateMatrix(theta_) * MakeTranslateMatrix(pos_) * camera.GetMatrix();
}

Vector2 Polygon::ApplyPosition(const Vector2& pos) {
	return pos * matrix_;
};
