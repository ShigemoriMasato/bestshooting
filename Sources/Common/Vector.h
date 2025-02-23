#pragma once

struct Matrix3x3;

struct IVector2 {
    int x;
    int y;

    // 演算子オーバーロード
    IVector2 operator+(const IVector2& vec) const;
    IVector2 operator-(const IVector2& vec) const;
    IVector2 operator*(float value) const;
    IVector2 operator/(float value) const;
    IVector2 operator*(const IVector2& value) const;
    IVector2 operator/(const IVector2& value) const;

    IVector2& operator+=(const IVector2& vec);
    IVector2& operator-=(const IVector2& vec);
    IVector2& operator*=(float value);
    IVector2& operator/=(float value);
    IVector2& operator*=(const IVector2& value);
    IVector2& operator/=(const IVector2& value);
};

struct Vector2 {
    float x;
    float y;

    // コンストラクタ
    Vector2() : x(0.0f), y(0.0f) {}
    Vector2(float x, float y) : x(x), y(y) {}

    // 演算子オーバーロード
    Vector2 operator+(const Vector2& vec) const;
    Vector2 operator-(const Vector2& vec) const;
    Vector2 operator*(float value) const;
    Vector2 operator/(float value) const;
    Vector2 operator*(const Vector2& value) const;
    Vector2 operator/(const Vector2& value) const;

    Vector2& operator+=(const Vector2& vec);
    Vector2& operator-=(const Vector2& vec);
    Vector2& operator*=(float value);
    Vector2& operator/=(float value);
    Vector2& operator*=(const Vector2& value);
    Vector2& operator/=(const Vector2& value);

    Vector2 operator*(const Matrix3x3& mat) const;
    Vector2& operator*=(const Matrix3x3& mat);
};

struct Matrix3x3 {
    float m[3][3];

    Matrix3x3 operator*(const Matrix3x3& mat) const;
    Vector2 operator*(const Vector2& vec) const;

    Matrix3x3& operator*=(const Matrix3x3& mat);
};

/// <summary>
/// アフィン行列を作成する関数
/// </summary>
namespace MakeMatrix {

    Matrix3x3 MakeScaleMatrix(const Vector2& scale);

    Matrix3x3 MakeRotateMatrix(float theta);

    Matrix3x3 MakeTranslateMatrix(const Vector2& pos);

    Matrix3x3 Inverse(const Matrix3x3& mat);

}