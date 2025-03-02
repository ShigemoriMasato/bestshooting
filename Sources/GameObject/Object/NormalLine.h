#pragma once
#include "../Common/Line.h"

class NormalLine : public Line {
public:

	NormalLine(Vector2 begin = {}, Vector2 end = {}, float width = 1) : Line(begin, end, width) {}

	virtual void Update(Camera& camera) = 0;

private:


};

