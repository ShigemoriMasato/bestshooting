#pragma once
#include "Common/Object.h"

class UI : public Object {
public:

	UI(Vector2 pos, Vector2 size, ObjectType type);
	~UI() = default;

	bool CollitionChecker(Vector2 pos);

private:

	bool isHit_;			//カーソルが当たっているかどうか
	bool isclicked_;		//クリックされたかどうか
};
