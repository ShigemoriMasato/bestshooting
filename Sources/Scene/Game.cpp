#include "Game.h"
#include "Title.h"
#include "Play/PlayData.h"
#include "Play/PlayScene.h"
#include "Play/Play.h"

Game::Game(std::shared_ptr<CommonData> commonData) : 
	Scene(commonData), 
	commonData_(commonData),
	playData_(std::make_shared<PlayData>()) {
	scene_ = std::make_unique<Play>(commonData, playData_);
}

Game::~Game() {
}

void Game::Initialize() {
}

std::unique_ptr<Scene> Game::Update() {

	std::unique_ptr<PlayScene> nextScene = scene_->Update();

	if (nextScene != nullptr) {
		scene_ = std::move(nextScene);
	}

	if (playData_->isTitle) {
		return std::make_unique<Title>(commonData_);
	}

	return nullptr;
}

void Game::Draw() const {
	scene_->Draw();
}
