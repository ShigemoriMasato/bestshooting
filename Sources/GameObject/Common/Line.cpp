#include "Line.h"
#include "../../Common/MyMath.h"
#include <cmath>

using namespace MyMath;

Line::Line(Vector2 begin, Vector2 end, float width) {
	begin_ = begin;
	end_ = end;
	width_ = width;

	blendMode_ = kBlendModeNormal;

	spos_[0] = {};
	spos_[1] = {};
	direction_ = {};
	sColor_ = 0;
}

void Line::Ready(Camera& camera, int bright) {
	float length = Distance(begin_, end_);

	pos_ = begin_;
	MakeAffineMatrix(camera);
	spos_[0] = ApplyPosition({ 0, 0 });

	pos_ = end_;
	MakeAffineMatrix(camera);
	spos_[1] = ApplyPosition({ 0, 0 });

	direction_ = Normalize(spos_[1] - spos_[0]);

	sColor_ = AdjustColor(bright);
}

void Line::Draw() {
	Novice::SetBlendMode(blendMode_);

	Novice::DrawLine(static_cast<int>(roundf(spos_[0].x)), static_cast<int>(roundf(spos_[0].y)),
		static_cast<int>(roundf(spos_[1].x)), static_cast<int>(roundf(spos_[1].y)),
		sColor_);
}
