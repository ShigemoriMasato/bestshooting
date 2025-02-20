#include "Object.h"
#include <cmath>
#include <algorithm>

using namespace MakeMatrix;
using MT = MatrixType;

namespace {
    /// ç≈ëÂí∑ÇäÓÇ…É|ÉCÉìÉgÇê≥ãKâªÇµÇ‹Ç∑ÅB
    Vector2 GetShapePoint(float x, float y, float length) {
        return { x / length, y / length };
    }

    /// ê≥ãKâªÇÃÇΩÇﬂÇÃç≈ëÂí∑Çå©Ç¬ÇØÇ‹Ç∑ÅB
    float SearchMaxLength(const std::vector<Vector2>& positions) {
        float maxLength = 0.0f;
        for (const auto& pos : positions) {
            float length = std::sqrtf(pos.x * pos.x + pos.y * pos.y);
            if (length > maxLength) {
                maxLength = length;
            }
        }
        return maxLength > 0.0f ? maxLength : 1.0f; // É[ÉçèúéZÇîÇØÇÈ
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

void Object::Ready(MatrixType type, int bright, const Camera& camera) {

    switch (type) {
    case MT::kSRT:
        matrix_ = MakeScaleMatrix(scale_) * MakeRotateMatrix(theta_) * MakeTranslateMatrix(pos_) * camera->GetMatrix();
        break;
    case MT::kSTR:
        matrix_ = MakeTranslateMatrix(pos_) * MakeScaleMatrix(scale_) * MakeRotateMatrix(theta_) * camera->GetMatrix();
        break;
    case MT::kScreenSRT:
        matrix_ = MakeScaleMatrix(scale_) * MakeRotateMatrix(theta_) * MakeTranslateMatrix(pos_);
        break;
    case MT::kScreenSTR:
        matrix_ = MakeTranslateMatrix(pos_) * MakeScaleMatrix(scale_) * MakeRotateMatrix(theta_);
        break;
    }
    
    for (int i = 0; i < npos_.size(); i++) {
        spos_[i] = Vector2(npos_[i].x * size_.x, npos_[i].y * size_.y) * matrix_;
    }

    smidPos_ = Vector2(0, 0) * matrix_;

    AdjustColor(bright);

}

void Object::Draw() {

    Novice::SetBlendMode(blendMode_);

    switch (type_) {
    case ObjectType::kCircle:

        Novice::DrawEllipse(static_cast<int>(smidPos_.x), static_cast<int>(smidPos_.y),
            static_cast<int>(size_.x), static_cast<int>(size_.y), theta_,
            color_, fillMode_);

        break;

    case ObjectType::kLine:

        Novice::DrawLine(static_cast<int>(spos_[0].x), static_cast<int>(spos_[0].y),
            static_cast<int>(spos_[1].x), static_cast<int>(spos_[1].y),
            color_);

        break;

    default:

        if (fillMode_ == kFillModeSolid) {
            for (int i = 1; i < spos_.size(); i++) {

                Novice::DrawTriangle(static_cast<int>(smidPos_.x), static_cast<int>(smidPos_.y),
                    static_cast<int>(spos_[i - 1].x), static_cast<int>(spos_[i - 1].y),
                    static_cast<int>(spos_[i].x), static_cast<int>(spos_[i].y),
                    color_, kFillModeSolid);

            }

            Novice::DrawTriangle(static_cast<int>(smidPos_.x), static_cast<int>(smidPos_.y),
                static_cast<int>(spos_[spos_.size() - 1].x), static_cast<int>(spos_[spos_.size() - 1].y),
                static_cast<int>(spos_[0].x), static_cast<int>(spos_[0].y),
                color_, kFillModeSolid);

        } else {
            for (int i = 1; i < spos_.size(); i++) {

                Novice::DrawLine(static_cast<int>(spos_[i - 1].x), static_cast<int>(spos_[i - 1].y),
                    static_cast<int>(spos_[i].x), static_cast<int>(spos_[i].y),
                    color_);

            }

            Novice::DrawLine(static_cast<int>(spos_[spos_.size() - 1].x), static_cast<int>(spos_[spos_.size() - 1].y),
                static_cast<int>(spos_[0].x), static_cast<int>(spos_[0].y),
                color_);
        }

        break;

    }

}

void Object::Initialize(const Vector2& size, FillMode fillMode, ObjectType type, const std::vector<Vector2>& localPositions) {
    size_ = size;
    fillMode_ = fillMode;
    type_ = type;

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
