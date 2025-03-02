#pragma once
#include "Object.h"

class UI : public Object {
public:

	UI(Vector2 pos, Vector2 size, ObjectType type);
	~UI() = default;

	virtual void Update(Camera& camera) = 0;

	bool CollitionChecker(Vector2 pos);

	bool GetIsClicked() const;

protected:

	bool isHit_;			//カーソルが当たっているかどうか
	bool isClicked_;		//クリックされたかどうか

};
