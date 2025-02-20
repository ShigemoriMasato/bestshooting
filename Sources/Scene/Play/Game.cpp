#include "Game.h"

Game::Game(std::shared_ptr<CommonData> commonData, std::shared_ptr<PlayData> playData_) : PlayScene(commonData, playData_) {
	Initialize();
}

Game::~Game() {
}

void Game::Initialize() {
}

std::unique_ptr<PlayScene> Game::Update() {
	return nullptr;
}

void Game::Draw() const {
}
