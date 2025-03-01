#include "BeginCircle.h"
#include "../../Common/MyMath.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define WAIT 4

using namespace MyMath;

BeginCircle::BeginCircle(int num) : NormalObject(ObjectType::kCircle) {
	//size_ = { 735 , 735 };
	size_ = { 128, 128 };
	pos_ = { 640, 360 };
	flame_ = 0;
	num_ = num;

	color_ = num % 2 == 0 ? 0xffffffff : 0xff;
}

void BeginCircle::Update(Camera& camera) {

	flame_++;

	if (flame_ > num_ * WAIT) {

		float t = cosf(float(flame_ - num_ * WAIT) * float(M_PI_2) / 15);

		scale_ = { t, t };

		if (flame_ > num_ * WAIT + 15) {
			isActive_ = false;
		}
	}

	Ready(camera, 255);
}
