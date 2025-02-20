#include "Camera.h"

using namespace MakeMatrix;

Camera::Camera() {
	pos_ = Vector2(640.0f, 360.0f);
	scale_ = Vector2(1, 1);
	theta_ = 0;
}

void Camera::Update() {
	matrix_ = MakeViewMatrix() * MakeOrthographicProjectionMatrix() * MakeViewportMatrix();
}

Matrix3x3 Camera::GetMatrix() const {
	return this->matrix_;
}

Matrix3x3 Camera::MakeViewMatrix() const {
	return MakeTranslateMatrix(pos_ * -1.0f) * MakeRotateMatrix(-theta_) * MakeScaleMatrix(scale_);
}

/// <summary>
/// 画面の中央をズームすることしかできない。変更するにはpos_を考慮した行列を作成する。今はめんどくさいのでしない
/// </summary>
Matrix3x3 Camera::MakeOrthographicProjectionMatrix() const {
	return {
		{
			{2.0f / WinSizeWidth, 0, 0},
			{0, 2.0f / WinSizeHeight, 0},
			{0 / WinSizeWidth, 0 / WinSizeHeight, 1}
		}
	};
}

Matrix3x3 Camera::MakeViewportMatrix() const {
	return {
		{
			{WinSizeWidth / 2, 0, 0},
			{0, -WinSizeHeight / 2, 0},
			{WinSizeWidth / 2, WinSizeHeight / 2, 1}
		}
	};
}
