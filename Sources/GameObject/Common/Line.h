#pragma once
#include "Polygon.h"

class Line : public Polygon {
public:

	Line(Vector2 begin = {}, Vector2 end = {}, float width = 1);
	~Line() = default;

	void Ready(Camera& camera, int bright = 255);

	virtual void Draw();

protected:

	Vector2 begin_;						//始点
	Vector2 end_;						//終点

	float width_;						//線の太さ

private:

	Vector2 spos_[2];					//screenPos
	Vector2 direction_;					//始点から終点への単位ベクトル
	float swidth_;						//screenWidth
	BlendMode blendMode_;               // ブレンドモード

	unsigned int sColor_;               //スクリーンに描画する用の色

};
