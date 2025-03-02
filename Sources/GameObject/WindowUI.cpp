#include "WindowUI.h"
#include "Cursol.h"

WindowUI::WindowUI(Vector2 pos, Vector2 size) : UI(pos, size, ObjectType::kQuad) {
	basicColor_ = 0xffffff00;
}

void WindowUI::Update(Camera& camera) {
	if (CollitionChecker(Cursol::GetCursolPos(camera))) {
		color_ = (basicColor_ & 0xffffff00) + 0xe0;

		if (Novice::IsPressMouse(0)) {
			isClicked_ = true;
		}

	} else {
		color_ = (basicColor_ & 0xffffff00) + 0x80;
	}

	Ready(camera, 255);
}

void WindowUI::SetBasicColor(unsigned int color) {
	this->basicColor_ = color & 0xffffff00;
}
