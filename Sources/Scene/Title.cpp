#include "Title.h"
#include "Game.h"

Title::Title(std::shared_ptr<CommonData> commonData) : Scene(commonData) {
	Initialize();
	cursol_ = Cursol();
}

Title::~Title() {
}

void Title::Initialize() {
}

std::unique_ptr<Scene> Title::Update() {

	cursol_.Update(commonData_->camera);

	if (commonData_->keys[DIK_F] && !commonData_->preKeys[DIK_F]) {
		return std::make_unique<Game>(commonData_);
	}

	return nullptr;
}

void Title::Draw() const {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xff8000ff, kFillModeSolid);

	cursol_.Draw();
}
