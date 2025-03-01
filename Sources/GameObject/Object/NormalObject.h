#pragma once
#include "../Common/Object.h"

class NormalObject : public Object {
public:

	NormalObject(ObjectType type, std::vector<Vector2> npos = {});

	virtual void Update(Camera& camera) = 0;

protected:

};

