#pragma once
#include "Common/UI.h"

class WindowUI : public UI {
public:

	WindowUI(Vector2 pos, Vector2 size);
	~WindowUI() = default;

	void Update(Camera& camera) override;

	void SetBasicColor(unsigned int color);

private:

	unsigned int basicColor_;		//基本色

};
