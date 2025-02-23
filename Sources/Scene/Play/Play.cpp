#include "Play.h"
#include "../Title.h"
#include "PlayData.h"

Play::Play(std::shared_ptr<CommonData> commonData, std::shared_ptr<PlayData> playData_) : PlayScene(commonData, playData_) {
	Initialize();
}

Play::~Play() {
}

void Play::Initialize() {
	player_ = Player();
}

std::unique_ptr<PlayScene> Play::Update() {
	//さっきのキー入力とかの処理を呼び出す
	player_.Update(commonData_->keys, commonData_->camera);

	//SEの再生
	if (commonData_->keys[DIK_F] && !commonData_->preKeys[DIK_F]) {
		commonData_->flugSE_[int(SE::test)] = true;
	}
	
	//BGMの再生
	if (commonData_->keys[DIK_G]) {
		commonData_->flugBGM_[int(BGM::test)] = true;
	}
	
	//BGMの停止
	if (commonData_->keys[DIK_T]) {
		commonData_->flugBGM_[int(BGM::test)] = false;
	}

	return nullptr;
}

void Play::Draw() const {
	player_.Draw();
}
