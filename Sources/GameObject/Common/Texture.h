#pragma once
#include "Polygon.h"
class Texture : public Polygon {
public:

	Texture();
	~Texture() = default;

	Texture(int textureHandle, Vector2 size);

	void Initialize(int textureHandle = 0, Vector2 size = {});

	void Ready(Camera& camera, int bright = 255);

	void Draw();

protected:

	Vector2 texturePos_;			//画像の描画位置(default: (0, 0))

private:

	Vector2 lpos_[4];				//ローカル座標
	Vector2 spos_[4];				//スクリーン座標

	int textureHandle_;				//画像のハンドル
	unsigned int sColor_;			//画像の色
};

