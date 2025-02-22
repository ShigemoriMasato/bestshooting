#include "Object.h"
#include "Camera.h"
#include <cmath>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace MakeMatrix;
using MT = MatrixType;

namespace {
    /// 最大長を基にポイントを正規化します。
    Vector2 GetShapePoint(float x, float y, float length) {
        return { x / length, y / length };
    }

    /// 正規化のための最大長を見つけます。
    float SearchMaxLength(const std::vector<Vector2>& positions) {
        float maxLength = 0.0f;
        for (const auto& pos : positions) {
            float length = std::sqrtf(pos.x * pos.x + pos.y * pos.y);
            if (length > maxLength) {
                maxLength = length;
            }
        }
        return maxLength > 0.0f ? maxLength : 1.0f; // ゼロ除算を避ける
    }
}

Object::Object() {
	Initialize({32, 32}, kFillModeSolid, ObjectType::kQuad, {});
}

Object::Object(const Vector2& size, FillMode fillMode, ObjectType type, const std::vector<Vector2>& localPositions):
	npos_(localPositions),
	type_(type) {
	Initialize(size, fillMode, type, localPositions);
}

void Object::Ready(const Camera& camera, int bright) {

	MakeAffineMatrix(camera);

    for (int i = 0; i < npos_.size(); i++) {
		spos_[i] = ApplyPosition(npos_[i] * size_);
    }

	smidPos_ = ApplyPosition({ 0.0f, 0.0f });

    sColor_ = AdjustColor(bright);
}

void Object::Draw() const {

    if (!isActive_) {
		return;
    }

    Novice::SetBlendMode(blendMode_);

    switch (type_) {
    case ObjectType::kCircle:

        Novice::DrawEllipse(static_cast<int>(smidPos_.x), static_cast<int>(smidPos_.y),
            static_cast<int>(size_.x), static_cast<int>(size_.y), theta_,
            sColor_, fillMode_);

        break;

    case ObjectType::kLine:

        Novice::DrawLine(static_cast<int>(spos_[0].x), static_cast<int>(spos_[0].y),
            static_cast<int>(spos_[1].x), static_cast<int>(spos_[1].y),
            sColor_);

        break;

    default:

        if (fillMode_ == kFillModeSolid) {
            for (int i = 1; i < spos_.size(); i++) {

                Novice::DrawTriangle(static_cast<int>(roundf(smidPos_.x)), static_cast<int>(roundf(smidPos_.y)),
                    static_cast<int>(roundf(spos_[i - 1].x)), static_cast<int>(roundf(spos_[i - 1].y)),
                    static_cast<int>(roundf(spos_[i].x)), static_cast<int>(roundf(spos_[i].y)),
                    sColor_, kFillModeSolid);

            }

            Novice::DrawTriangle(static_cast<int>(smidPos_.x), static_cast<int>(smidPos_.y),
                static_cast<int>(spos_[spos_.size() - 1].x), static_cast<int>(spos_[spos_.size() - 1].y),
                static_cast<int>(spos_[0].x), static_cast<int>(spos_[0].y),
                sColor_, kFillModeSolid);

        } else {

            for (int i = 1; i < spos_.size(); i++) {

                Novice::DrawLine(static_cast<int>(spos_[i - 1].x), static_cast<int>(spos_[i - 1].y),
                    static_cast<int>(spos_[i].x), static_cast<int>(spos_[i].y),
                    sColor_);

            }

            Novice::DrawLine(static_cast<int>(spos_[spos_.size() - 1].x), static_cast<int>(spos_[spos_.size() - 1].y),
                static_cast<int>(spos_[0].x), static_cast<int>(spos_[0].y),
                sColor_);
        }

        break;

    }

}

void Object::Initialize(const Vector2& size, FillMode fillMode, ObjectType type, const std::vector<Vector2>& localPositions) {
    size_ = size;
    scale_ = { 1.0f, 1.0f };

    fillMode_ = fillMode;
    type_ = type;
	
    bright_ = 255;
    isActive_ = true;
	isBlackout_ = true;

    blendMode_ = kBlendModeNormal;
	SetColor(0xffffffff);

    switch (type_) {
    case ObjectType::kCircle:
        npos_.push_back({ 0.0f, 0.0f });
        break;
    case ObjectType::kLine:
        npos_ = { {1.0f, 0.0f}, {-1.0f, 0.0f} };
        break;
    case ObjectType::kTriangle:
        npos_ = { {0.0f, 1.0f}, {-1.0f, -1.0f}, {1.0f, -1.0f} };
        break;
    case ObjectType::kQuad:
        npos_ = { {1.0f, 1.0f}, {-1.0f, 1.0f}, {-1.0f, -1.0f}, {1.0f, -1.0f} };
        break;
    case ObjectType::kCustom:
        if (!localPositions.empty()) {
            float maxLength = SearchMaxLength(localPositions);
            for (const auto& pos : localPositions) {
                npos_.push_back(GetShapePoint(pos.x, pos.y, maxLength));
            }
        }
        break;
    }

    spos_.resize(npos_.size());
}
