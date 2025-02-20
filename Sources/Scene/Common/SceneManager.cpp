#include "SceneManager.h"
#include "Scene.h"
#include "../Title.h"
#include "../CommonData.h"

SceneManager::SceneManager() : commonData_(std::make_shared<CommonData>()) {
	//最初のシーンを挿入する
	scene_ = std::make_unique<Title>(commonData_);
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

//お試しでconstを付ける。できるだけ更新と描画を分けられるようにする。無理な場合は外す
void SceneManager::Draw() const {
	scene_->Draw();
}
