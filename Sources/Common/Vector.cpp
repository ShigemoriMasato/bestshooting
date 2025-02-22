#include "Vector.h"
#include <cassert>
#include <cmath>

//=========================================================================================
// 
// 0での除算防止をする際、あまりにも小さい数でも演算結果が膨れ上がり、エラーのもとになるため、少ない数でも除外対象とする
// 
//=========================================================================================

Vector2 Vector2::operator+(const Vector2& vec) const {
    return Vector2(x + vec.x, y + vec.y);
}

Vector2 Vector2::operator-(const Vector2& vec) const {
    return Vector2(x - vec.x, y - vec.y);
}

Vector2 Vector2::operator*(float value) const {
    return Vector2(x * value, y * value);
}

Vector2 Vector2::operator/(float value) const {
    assert(std::abs(value) > 1e-5f); //0での除算防止
    return Vector2(x / value, y / value);
}

Vector2 Vector2::operator*(const Vector2& vec) const {
    return Vector2(x * vec.x, y * vec.y);
}

Vector2 Vector2::operator/(const Vector2& vec) const {
    assert(std::abs(vec.x) > 1e-5f && std::abs(vec.y) > 1e-5f); //0での除算防止
    return Vector2(x / vec.x, y / vec.y);
}

Vector2& Vector2::operator+=(const Vector2& vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vector2& Vector2::operator*=(float value) {
    x *= value;
    y *= value;
    return *this;
}

Vector2& Vector2::operator/=(float value) {
    assert(std::abs(value) > 1e-5f);
    x /= value;
    y /= value;
    return *this;
}

Vector2& Vector2::operator*=(const Vector2& vec) {
    x *= vec.x;
    y *= vec.y;
    return *this;
}

Vector2& Vector2::operator/=(const Vector2& vec) {
    assert(std::abs(vec.x) > 1e-5f && std::abs(vec.y) > 1e-5f);
    x /= vec.x;
    y /= vec.y;
    return *this;
}

Vector2 Vector2::operator*(const Matrix3x3& mat) const {
	float w = x * mat.m[0][2] + y * mat.m[1][2] + mat.m[2][2];
	assert(std::abs(w) > 1e-5f);
	return Vector2(
		(x * mat.m[0][0] + y * mat.m[1][0] + mat.m[2][0]) / w,
		(x * mat.m[0][1] + y * mat.m[1][1] + mat.m[2][1]) / w
	);
}

Vector2& Vector2::operator*=(const Matrix3x3& mat) {
    float tx = x * mat.m[0][0] + y * mat.m[1][0] + mat.m[2][0];
    float ty = x * mat.m[0][1] + y * mat.m[1][1] + mat.m[2][1];
    float w = x * mat.m[0][2] + y * mat.m[1][2] + mat.m[2][2];
    assert(std::abs(w) > 1e-5f);
    x = tx / w;
    y = ty / w;
    return *this;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& mat) const {
    Matrix3x3 result = {};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.m[i][j] = 0.0f;
            for (int k = 0; k < 3; ++k) {
                result.m[i][j] += m[i][k] * mat.m[k][j];
            }
        }
    }
    return result;
}

Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& mat) {
    *this = *this * mat;
    return *this;
}

Vector2 Matrix3x3::operator*(const Vector2& vec) const {
	return vec * *this;
}

namespace MakeMatrix {

    Matrix3x3 MakeScaleMatrix(const Vector2& scale) {
        Matrix3x3 mat = {};
        mat.m[0][0] = scale.x;
        mat.m[1][1] = scale.y;
        mat.m[2][2] = 1.0f;
        return mat;
    }

    Matrix3x3 MakeRotateMatrix(float theta) {
        Matrix3x3 mat = {};
        float cosTheta = cosf(theta);
        float sinTheta = sinf(theta);

        mat.m[0][0] = cosTheta;
        mat.m[0][1] = -sinTheta;
        mat.m[1][0] = sinTheta;
        mat.m[1][1] = cosTheta;
        mat.m[2][2] = 1.0f;

        return mat;
    }

    Matrix3x3 MakeTranslateMatrix(const Vector2& pos) {
        Matrix3x3 mat = {};
        mat.m[0][0] = 1.0f;
        mat.m[1][1] = 1.0f;
        mat.m[2][0] = pos.x;
        mat.m[2][1] = pos.y;
        mat.m[2][2] = 1.0f;
        return mat;
    }

    Matrix3x3 Inverse(const Matrix3x3& mat) {
        float det =
            mat.m[0][0] * (mat.m[1][1] * mat.m[2][2] - mat.m[1][2] * mat.m[2][1]) -
            mat.m[0][1] * (mat.m[1][0] * mat.m[2][2] - mat.m[1][2] * mat.m[2][0]) +
            mat.m[0][2] * (mat.m[1][0] * mat.m[2][1] - mat.m[1][1] * mat.m[2][0]);

        assert(std::abs(det) > 1e-5f); //0での除算防止

        Matrix3x3 inv = {};
        inv.m[0][0] = (mat.m[1][1] * mat.m[2][2] - mat.m[1][2] * mat.m[2][1]) / det;
        inv.m[0][1] = -(mat.m[0][1] * mat.m[2][2] - mat.m[0][2] * mat.m[2][1]) / det;
        inv.m[0][2] = (mat.m[0][1] * mat.m[1][2] - mat.m[0][2] * mat.m[1][1]) / det;

        inv.m[1][0] = -(mat.m[1][0] * mat.m[2][2] - mat.m[1][2] * mat.m[2][0]) / det;
        inv.m[1][1] = (mat.m[0][0] * mat.m[2][2] - mat.m[0][2] * mat.m[2][0]) / det;
        inv.m[1][2] = -(mat.m[0][0] * mat.m[1][2] - mat.m[0][2] * mat.m[1][0]) / det;

        inv.m[2][0] = (mat.m[1][0] * mat.m[2][1] - mat.m[1][1] * mat.m[2][0]) / det;
        inv.m[2][1] = -(mat.m[0][0] * mat.m[2][1] - mat.m[0][1] * mat.m[2][0]) / det;
        inv.m[2][2] = (mat.m[0][0] * mat.m[1][1] - mat.m[0][1] * mat.m[1][0]) / det;

        return inv;
    }

}
