#pragma once
#include "Vector.h"
#define WinSizeWidth 1280		//画面の横幅
#define WinSizeHeight 720		//画面の縦幅

class Camera {
public:

	Camera();

	void Update();

	Matrix3x3 GetMatrix() const;

	void SetPos(const Vector2& pos) { pos_ = pos; }
	void SetScale(const Vector2& scale) { scale_ = scale; }
	void SetTheta(float theta) { theta_ = theta; }
	void SetMidPos(const Vector2& midPos) { midPos_ = midPos; }

private:

	Matrix3x3 MakeViewMatrix() const;
	Matrix3x3 MakeOrthographicProjectionMatrix() const;
	Matrix3x3 MakeViewportMatrix() const;

	Vector2 pos_;
	Vector2 midPos_;
	Vector2 scale_;
	float theta_;

	Matrix3x3 matrix_;
};

