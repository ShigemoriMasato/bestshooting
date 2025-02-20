#pragma once
#include "Vector.h"
#define WinSizeWidth 1280		//��ʂ̉���
#define WinSizeHeight 720		//��ʂ̏c��

class Camera {
public:

	Camera();

	void Update();

	Matrix3x3 GetMatrix() const;

	Vector2 pos_;
	Vector2 scale_;
	float theta_;

private:

	Matrix3x3 MakeViewMatrix() const;
	Matrix3x3 MakeOrthographicProjectionMatrix() const;
	Matrix3x3 MakeViewportMatrix() const;

	Matrix3x3 matrix_;
};

