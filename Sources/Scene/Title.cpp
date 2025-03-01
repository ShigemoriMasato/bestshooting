#include "Title.h"
#include "Game.h"
#include "../GameObject/WindowUI.h"

Title::Title(std::shared_ptr<CommonData> commonData) : Scene(commonData) {
	Initialize();
}

Title::~Title() {
	uiList_.clear();
}

void Title::Initialize() {
	cursol_ = Cursol();
	uiList_.clear();
	uiList_.push_back(std::make_unique<WindowUI>(Vector2(360, 480), Vector2(200, 100)));
}

std::unique_ptr<Scene> Title::Update() {

	//==============Cursol==================
	cursol_.Update(commonData_->camera);

	//==============UI==================
	for (auto& ui : uiList_) {
		ui->Update(commonData_->camera);
	}

	//==============SceneChange==================
	for (int i = 0; i < uiList_.size(); i++) {
		if (uiList_[i]->GetIsClicked()) {
			commonData_->sceneNumber = i;

			return std::make_unique<Game>(commonData_);
		}
	}

	return nullptr;
}

void Title::Draw() const {
	//===============BackGround==================
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x000000ff, kFillModeSolid);

	//===============UI==================
	for (const auto& ui : uiList_) {
		ui->Draw();
	}

	//===============Cursol==================
	cursol_.Draw();
}
