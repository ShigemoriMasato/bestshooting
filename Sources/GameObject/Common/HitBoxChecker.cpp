#include "HitBoxChecker.h"
#include "../../Common/MyMath.h"

using namespace MyMath;

bool CollitionChecker::CircleToCircle(const Object& obj1, const Object& obj2) {
	if (Distance(obj1.GetPos(), obj2.GetPos()) < obj1.GetSize().x * obj1.GetScale().x + obj2.GetSize().x * obj2.GetScale().x) {
		return true;
	} else {
		return false;
	}
}

bool CollitionChecker::CircleToPoint(const Object& obj, const Vector2& point) {
	if (Distance(obj.GetPos(), point) < obj.GetSize().x * obj.GetScale().x) {
		return true;
	} else {
		return false;
	}
}

bool CollitionChecker::CircleToBox(const Object& obj1, const Object& obj2) {
	Vector2 nearest = obj2.GetPos();
	if (obj1.GetPos().x < obj2.GetPos().x - obj2.GetSize().x * obj2.GetScale().x / 2) {
		nearest.x = obj2.GetPos().x - obj2.GetSize().x * obj2.GetScale().x / 2;
	} else if (obj1.GetPos().x > obj2.GetPos().x + obj2.GetSize().x * obj2.GetScale().x / 2) {
		nearest.x = obj2.GetPos().x + obj2.GetSize().x * obj2.GetScale().x / 2;
	}

	if (obj1.GetPos().y < obj2.GetPos().y - obj2.GetSize().y * obj2.GetScale().y / 2) {
		nearest.y = obj2.GetPos().y - obj2.GetSize().y * obj2.GetScale().y / 2;
	} else if (obj1.GetPos().y > obj2.GetPos().y + obj2.GetSize().y * obj2.GetScale().y / 2) {
		nearest.y = obj2.GetPos().y + obj2.GetSize().y * obj2.GetScale().y / 2;
	}
	
	if (Distance(obj1.GetPos(), nearest) < obj1.GetSize().x * obj1.GetScale().x) {
		return true;
	} else {
		return false;
	}
}

bool CollitionChecker::BoxToBox(const Object& obj1, const Object& obj2) {
	if (obj1.GetPos().x - obj1.GetSize().x * obj1.GetScale().x / 2 < obj2.GetPos().x + obj2.GetSize().x * obj2.GetScale().x / 2 &&
		obj1.GetPos().x + obj1.GetSize().x * obj1.GetScale().x / 2 > obj2.GetPos().x - obj2.GetSize().x * obj2.GetScale().x / 2 &&
		obj1.GetPos().y - obj1.GetSize().y * obj1.GetScale().y / 2 < obj2.GetPos().y + obj2.GetSize().y * obj2.GetScale().y / 2 &&
		obj1.GetPos().y + obj1.GetSize().y * obj1.GetScale().y / 2 > obj2.GetPos().y - obj2.GetSize().y * obj2.GetScale().y / 2) {
		return true;
	} else {
		return false;
	}
}

bool CollitionChecker::BoxToPoint(const Object& obj, const Vector2& point) {
	if (obj.GetPos().x - obj.GetSize().x * obj.GetScale().x / 2 < point.x &&
		obj.GetPos().x + obj.GetSize().x * obj.GetScale().x / 2 > point.x &&
		obj.GetPos().y - obj.GetSize().y * obj.GetScale().y / 2 < point.y &&
		obj.GetPos().y + obj.GetSize().y * obj.GetScale().y / 2 > point.y) {
		return true;
	} else {
		return false;
	}
}
