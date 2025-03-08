#include "Polygon.h"
#include <cmath>

using namespace MakeMatrix;

unsigned int Polygon::AdjustColor(int bright) {
	unsigned int color = color_;

	float alpha = static_cast<float>(color & 0xff);
	color >>= 8;

	float blue = static_cast<float>(color & 0xff);
	color >>= 8;

	float green = static_cast<float>(color & 0xff);
	color >>= 8;

	float red = static_cast<float>(color);

	float ratio = bright_ / 255.0f;

	if (isBlackout_) {
		ratio *= bright / 255.0f;
	}

	return (static_cast<int>(roundf(alpha)) | (static_cast<int>(roundf(red * ratio)) << 24) | (static_cast<int>(roundf(green * ratio)) << 16) | static_cast<int>(roundf(blue * ratio)) << 8);
}

void Polygon::MakeAffineMatrix(const Camera& camera) {

	if (isApplyCamera_) {
		matrix_ = MakeScaleMatrix(scale_) * MakeRotateMatrix(theta_) * MakeTranslateMatrix(pos_) * camera.GetMatrix();
	} else {
		matrix_ = MakeScaleMatrix(scale_) * MakeRotateMatrix(theta_) * MakeTranslateMatrix(pos_);
	}
}

Vector2 Polygon::ApplyPosition(const Vector2& pos) {
	return pos * matrix_;
}


/*************************************************************************************************
*
*		アクセサーメソッド
*
**************************************************************************************************/

Vector2 Polygon::GetPos() const {
	return this->pos_;
};

Vector2 Polygon::GetSize() const {
	return this->size_;
}

Vector2 Polygon::GetScale() const {
	return this->scale_;
}

bool Polygon::GetIsActive() const {
	return this->isActive_;
}

void Polygon::SetColor(unsigned int color) {
	this->color_ = color;
}
