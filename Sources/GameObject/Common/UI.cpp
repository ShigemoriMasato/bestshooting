#include "UI.h"
#include "HitBoxChecker.h"

using namespace CollitionChecker;

UI::UI(Vector2 pos, Vector2 size, ObjectType type) : Object(size, kFillModeSolid, type) {
	pos_ = pos;
	isHit_ = false;
	isClicked_ = false;
}

bool UI::CollitionChecker(Vector2 pos) {

	switch (GetType()) {
	case ObjectType::kCircle:

		isHit_ = CircleToPoint(*this, pos);

		break;

	default:

		isHit_ = BoxToPoint(*this, pos);

		break;
	}

	return isHit_;

}

bool UI::GetIsClicked() const {
	return this->isClicked_;
}
