#include "MyMath.h"
#include <cmath>

using namespace MyMath;

float MyMath::Distance(const Vector2& vec1, const Vector2& vec2) {
	return sqrtf((vec2.x - vec1.x) * (vec2.x - vec1.x) + (vec2.y - vec1.y) * (vec2.y - vec1.y));
}

float MyMath::Length(const Vector2& vec) {
	return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

Vector2 MyMath::Normalize(const Vector2& vec) {
	float length = Length(vec);
	if (length == 0.0f) {
		return { 0.0f, 0.0f };
	}
	return vec / length;
}

float MyMath::Dot(const Vector2& vec1, const Vector2& vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

float MyMath::Cross(const Vector2& vec1, const Vector2& vec2) {
	return vec1.x * vec2.y - vec1.y * vec2.x;
}

Vector2 MyMath::Reflect(const Vector2& vec, const Vector2& normal) {
	return vec - normal * Dot(vec, normal) * 2.0f;
}

float MyMath::Lerp(float a, float b, float t) {
	return a + (b - a) * t;
}

Vector2 MyMath::Lerp(const Vector2 vec1, const Vector2 vec2, float t) {
	return vec1 + (vec2 - vec1) * t;
}

Vector2 MyMath::Rotate(const Vector2& vec, float theta) {
	return { vec.x * cosf(theta) - vec.y * sinf(theta), vec.x * sinf(theta) + vec.y * cosf(theta) };
}

unsigned int MyMath::ColorLerp(unsigned int a, unsigned int b, float t) {
	unsigned int lr = (unsigned int)((1.0f - t) * ((a >> 24) & 0xff) + t * ((b >> 24) & 0xff));
	unsigned int lg = (unsigned int)((1.0f - t) * ((a >> 16) & 0xff) + t * ((b >> 16) & 0xff));
	unsigned int lb = (unsigned int)((1.0f - t) * ((a >> 8) & 0xff) + t * ((b >> 8) & 0xff));
	unsigned int la = (unsigned int)((1.0f - t) * (a & 0xff) + t * (b & 0xff));
	return (lr << 24) | (lg << 16) | (lb << 8) | la;
}
