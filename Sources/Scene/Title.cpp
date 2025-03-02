#include "Title.h"
#include "Game.h"

Title::Title(std::shared_ptr<CommonData> commonData) : Scene(commonData) {
	Initialize();
}

Title::~Title() {
}

void Title::Initialize() {
}

std::unique_ptr<Scene> Title::Update() {

	if (cd->keys[DIK_F] && !cd->preKeys[DIK_F]) {
		return std::make_unique<Game>(cd);
	}

	return nullptr;

}

void Title::Draw() const {
}
