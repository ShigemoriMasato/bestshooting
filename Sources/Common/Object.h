#pragma once
#include "Polygon.h"
#include "Vector.h"
#include <vector>

class Camera;

enum class ObjectType {
    kCircle,
    kLine,
    kTriangle,
    kQuad,
    kCustom
};

class Object : public Polygon {
public:
    /// <summary>
	/// 32*32の四角形を作成する
    /// </summary>
    Object();

    /// <summary>
    /// Objectを作成する
    /// </summary>
    /// <param name="size">Objectの外枠</param>
    /// <param name="fillMode">内側を埋めるかどうか</param>
    /// <param name="type">プリセットを使用しない場合はcustom</param>
    /// <param name="localPositions">customの場合は各点の座標、それ以外は{}を入力</param>
    Object(const Vector2& size, FillMode fillMode, ObjectType type = ObjectType::kQuad, const std::vector<Vector2>& localPositions = {});
    virtual ~Object() = default;

    void Ready(MatrixType type, const Camera& camera, int bright = 255);

    virtual void Draw();

private:
    void Initialize(const Vector2& size, FillMode fillMode, ObjectType type, const std::vector<Vector2>& localPositions);

    std::vector<Vector2> npos_;  // 正規化されたローカル座標
    std::vector<Vector2> spos_;      // 変換されたスクリーン座標
    Vector2 smidPos_;              // スクリーン上の中心位置

    ObjectType type_;
    FillMode fillMode_;
	BlendMode blendMode_;
};
