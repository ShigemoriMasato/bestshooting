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

	return nullptr;
	
	//return std::make_unique<Play>(commonData_);
}

void Title::Draw() const {
}
