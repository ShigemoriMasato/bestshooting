#pragma once
#include "Vector.h"

namespace MyMath {

	float Distance(const Vector2& vec1, const Vector2& vec2);

	Vector2 Normalize(const Vector2& vec);

	float Dot(const Vector2& vec1, const Vector2& vec2);

	float Cross(const Vector2& vec1, const Vector2& vec2);

	float Length(const Vector2& vec);

	Vector2 Reflect(const Vector2& vec, const Vector2& normal);

	float Lerp(float a, float b, float t);

	Vector2 Lerp(const Vector2 vec1, const Vector2 vec2, float t);

	Vector2 Rotate(const Vector2& vec, float theta);

	unsigned int ColorLerp(unsigned int a, unsigned int b, float t);
};
