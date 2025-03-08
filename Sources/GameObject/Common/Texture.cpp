#include "Texture.h"

Texture::Texture() {
	Initialize();
}

Texture::Texture(int textureHandle, Vector2 size) {
	Initialize(textureHandle, size);
}

void Texture::Initialize(int textureHandle, Vector2 size) {
	size_ = size;
	scale_ = { 1.0f, 1.0f };

	textureHandle_ = textureHandle;
	texturePos_ = { 0.0f, 0.0f };

	bright_ = 255;
	isActive_ = true;
	isBlackout_ = false;
	isApplyCamera_ = true;

	blendMode_ = kBlendModeNormal;
	color_ = 0xffffffff;

	for (int i = 0; i < 4; i++) {
		lpos_[i] = { (float(i % 2) - 0.5f) * size_.x, (float((3 - i) / 2) - 0.5f) * size_.y };
	}
}

void Texture::Ready(Camera& camera, int bright) {

	MakeAffineMatrix(camera);

	for (int i = 0; i < 4; i++) {
		spos_[i] = ApplyPosition(lpos_[i]);
	}

	sColor_ = AdjustColor(bright);
}

void Texture::Draw() {

	if (!isActive_) {
		return;
	}
	
	Novice::SetBlendMode(blendMode_);
	
	Novice::DrawQuad(static_cast<int>(spos_[0].x), static_cast<int>(spos_[0].y),
		static_cast<int>(spos_[1].x), static_cast<int>(spos_[1].y),
		static_cast<int>(spos_[2].x), static_cast<int>(spos_[2].y),
		static_cast<int>(spos_[3].x), static_cast<int>(spos_[3].y),
		static_cast<int>(texturePos_.x * size_.x), static_cast<int>(texturePos_.y * size_.y), 
		static_cast<int>(size_.x), static_cast<int>(size_.y), textureHandle_, sColor_);
}
