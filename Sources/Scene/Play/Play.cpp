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
	cpos_ = { 640.0f, 360.0f };
	cscale_ = { 1.0f, 1.0f };
	ctheta_ = 0.0f;
}

std::unique_ptr<PlayScene> Play::Update() {

	if (cd_->keys[DIK_UPARROW]) {
		cpos_.y += 5;
	}

	if (cd_->keys[DIK_DOWNARROW]) {
		cpos_.y -= 5;
	}

	if (cd_->keys[DIK_LEFTARROW]) {
		cpos_.x -= 5;
	}

	if (cd_->keys[DIK_RIGHTARROW]) {
		cpos_.x += 5;
	}

	if (cd_->keys[DIK_J]) {
		ctheta_ += 0.1f;
	}

	if (cd_->keys[DIK_K]) {
		ctheta_ -= 0.1f;
	}

	if (cd_->keys[DIK_U]) {
		cscale_ += Vector2(0.1f, 0.1f);
	}

	if (cd_->keys[DIK_I]) {
		cscale_ -= Vector2(0.1f, 0.1f);
	}

	if (cd_->keys[DIK_G] && !cd_->preKeys[DIK_G]) {
		cd_->flugSE_[int(SE::PrivateTime)] = true;
	}

	cd_->camera.SetPos(cpos_);
	cd_->camera.SetScale(cscale_);
	cd_->camera.SetTheta(ctheta_);

	//さっきのキー入力とかの処理を呼び出す
	player_.Update(cd_->keys, cd_->camera);

	if (cd_->keys[DIK_F] && !cd_->preKeys[DIK_F]) {
		playData_->isTitle = true;
	}

	return nullptr;
}

void Play::Draw() const {
	player_.Draw();

	Novice::ScreenPrintf(0, 0, "cameraPos:	%f	%f", cpos_.x, cpos_.y);
	Novice::ScreenPrintf(0, 20, "cameraScale:	%f	%f", cscale_.x, cscale_.y);
	Novice::ScreenPrintf(0, 40, "cameraTheta:	%f", ctheta_);
}
