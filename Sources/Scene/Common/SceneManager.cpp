#include "SceneManager.h"
#include "Scene.h"
#include "../Game.h"
#include "../Title.h"
#include "../CommonData.h"
#include <Novice.h>

SceneManager::SceneManager() : commonData_(std::make_shared<CommonData>()) {
	//最初のシーンを挿入する
	scene_ = std::make_unique<Title>(commonData_);
}

SceneManager::~SceneManager() {
}

void SceneManager::Update() {
	//共通データの更新
	commonData_->Update();

	//シーン移行する場合はnew Sceneのstd版、それ以外はnullptrが返ってくる
	std::unique_ptr<Scene> nextScene = scene_->Update();

	//new Sceneが返ってきたらシーンを入れ替える(deleteは自動で行われる(std::unique_ptrの機能))
	if (nextScene != nullptr) {
		scene_ = std::move(nextScene);
	}
}

void SceneManager::Draw() const {
	commonData_->Draw();
	scene_->Draw();
}
