#include "Polygon.h"
#include <cmath>

void Polygon::AdjustColor(int bright) {
	float ratio = float(this->bright_) / 255;		//オブジェクト固有の明るさ

	if (isBlackout_) {
		ratio *= float(bright) / 255;				//ワールド全体の明るさ
	}

	//カラーに当てはめる
	this->color_ = (int(roundf(this->red_ * ratio)) << 24) + (int(roundf(this->green_ * ratio)) << 16) + (int(roundf(this->blue_ * ratio)) << 8) + (this->alpha_);
};
