#include "Play.h"
#include "Title.h"
#include "Play/PlayData.h"
#include "Play/PlayScene.h"
#include "Play/Game.h"

Play::Play(std::shared_ptr<CommonData> commonData) : 
	Scene(std::move(commonData)), 
	playData_(std::make_shared<PlayData>()) {
	
	scene_ = std::make_unique<Game>(commonData, playData_);

}

Play::~Play() {
}

void Play::Initialize() {
}

std::unique_ptr<Scene> Play::Update() {

	std::unique_ptr<PlayScene> nextScene = scene_->Update();

	if (nextScene != nullptr) {
		scene_ = std::move(nextScene);
	}

	if (playData_->isTitle) {
		return std::make_unique<Title>(commonData_);
	}

	return nullptr;
}

void Play::Draw() const {
	scene_->Draw();
}
