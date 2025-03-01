#pragma once
#include "Object.h"

namespace CollitionChecker {

	bool CircleToCircle(const Object& obj1, const Object& obj);

	bool CircleToPoint(const Object& obj, const Vector2& point);

	bool CircleToBox(const Object& obj1, const Object& obj2);

	bool BoxToBox(const Object& obj1, const Object& obj2);

	bool BoxToPoint(const Object& obj, const Vector2& point);

}
