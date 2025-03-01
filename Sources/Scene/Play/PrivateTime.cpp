#include "PrivateTime.h"
#include "../Title.h"
#include "PlayData.h"
#include "../../GameObject/Object/BeginCircle.h"

using namespace std;

PrivateTime::PrivateTime(shared_ptr<CommonData> commonData, shared_ptr<PlayData> playData_) : PlayScene(commonData, playData_) {
	Initialize();
}

PrivateTime::~PrivateTime() {
}

void PrivateTime::Initialize() {
	pd->bps_ = 140.0f / 60.0f;
	pd->safetySec_ = 0.5f;

	cpos_ = { 640.0f, 360.0f };
	cscale_ = { 1.0f, 1.0f };
	ctheta_ = 0.0f;
	
	cd->flugBGM_[int(BGM::PrivateTime)] = true;
	
	isFirst_ = true;
	pd->bps_ = 130.0f / 60;
	for (int i = 0; i < 5; i++) {
		objects_.push_back(make_unique<BeginCircle>(i));
	}
}

unique_ptr<PlayScene> PrivateTime::Update() {

	//音を流す処理
	if (isFirst_) {
		isFirst_ = false;
		cd->flugBGM_[int(BGM::PrivateTime)] = true;
	}

	//タイトルに戻る
	if (!cd->flugBGM_[int(BGM::PrivateTime)] || cd->keys[DIK_SPACE]) {
		pd->isTitle = true;
		cd->flugBGM_[int(BGM::PrivateTime)] = false;
		return nullptr;
	}

	for (int i = 0; i < int(objects_.size()); i++) {
		objects_[i]->Update(cd->camera);

		if (objects_[i]->GetIsActive() == false) {
			objects_.erase(objects_.begin() + i--);
		}
	}
	
	return nullptr;
}

void PrivateTime::Draw() const {
	//背景
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xff, kFillModeSolid);

	Novice::ScreenPrintf(0, 0, "beat : %d", pd->beat_);
	Novice::ScreenPrintf(0, 20, "flame : %d", pd->flame_);
	Novice::ScreenPrintf(0, 40, "seconds : %f", pd->seconds_);

	for (int i = int(objects_.size()) - 1; i >= 0; i--) {
		objects_[i]->Draw();
	}
}
