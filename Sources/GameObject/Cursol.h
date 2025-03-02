#pragma once
#include "Common/Object.h"

class Cursol : public Object {
public:

	Cursol();
	~Cursol() = default;

	static Vector2 GetCursolPos(Camera& camera);

	void Update(Camera& camera);

private:

};

