#include "SceneManager.h"
#include "Scene.h"
#include "../Game.h"
#include "../CommonData.h"
#include <Novice.h>

SceneManager::SceneManager() : commonData_(std::make_shared<CommonData>()) {
	//最初のシーンを挿入する
	scene_ = std::make_unique<Game>(commonData_);
}

SceneManager::~SceneManager() {
}

void SceneManager::Update() {
	commonData_->Update();

	//シーン移行する場合はnew Sceneのstd版、それ以外はnullptrが返ってくる
	std::unique_ptr<Scene> nextScene = scene_->Update();

	//移行するかどうかの判断
	if (nextScene != nullptr) {
		scene_ = std::move(nextScene);
	}
}

void SceneManager::Draw() const {
	commonData_->Draw();
	scene_->Draw();
}
