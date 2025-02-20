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
	/// 32*32�̎l�p�`���쐬����
    /// </summary>
    Object();

    /// <summary>
    /// Object���쐬����
    /// </summary>
    /// <param name="size">Object�̊O�g</param>
    /// <param name="fillMode">�����𖄂߂邩�ǂ���</param>
    /// <param name="type">�v���Z�b�g���g�p���Ȃ��ꍇ��custom</param>
    /// <param name="localPositions">custom�̏ꍇ�͊e�_�̍��W�A����ȊO��{}�����</param>
    Object(const Vector2& size, FillMode fillMode, ObjectType type = ObjectType::kQuad, const std::vector<Vector2>& localPositions = {});
    virtual ~Object() = default;

    void Ready(MatrixType type, int bright = 255, const Camera& camera);

    virtual void Draw();

private:
    void Initialize(const Vector2& size, FillMode fillMode, ObjectType type, const std::vector<Vector2>& localPositions);

    std::vector<Vector2> npos_;  // ���K�����ꂽ���[�J�����W
    std::vector<Vector2> spos_;      // �ϊ����ꂽ�X�N���[�����W
    Vector2 smidPos_;              // �X�N���[����̒��S�ʒu

    ObjectType type_;
    FillMode fillMode_;
	BlendMode blendMode_;
};
