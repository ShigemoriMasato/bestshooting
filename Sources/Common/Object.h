#pragma once
#include "Polygon.h"

class Object : Polygon {
public:

	Object() = default;
	void Initialize();
	void Update();
	void Draw() const;

private:

};

