#include "UI.h"

UI::UI(Vector2 pos, Vector2 size, ObjectType type) : Object(size, kFillModeSolid, type) {
	pos_ = pos;
}

bool UI::CollitionChecker(Vector2 pos) {
	pos;
	switch (GetType()) {
	case ObjectType::kCircle:



		break;

	case ObjectType::kQuad:

		break;

	default:

		isHit_ = false;

		break;
	}

	return isHit_;

}
