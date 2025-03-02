#pragma once
#include "NormalLine.h"

class FadeLine : public NormalLine {
public:

	FadeLine(Vector2 begin, Vector2 end, float width);
	~FadeLine() = default;

	void Fade();

private:



};

