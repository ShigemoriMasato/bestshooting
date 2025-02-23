#include "CommonData.h"
#include <Novice.h>
#include <memory>

CommonData::CommonData() {
	flugBGM_.resize(static_cast<int>(BGM::AllCount));
	flugSE_.resize(static_cast<int>(SE::AllCount));

	soundManager_ = SoundManager();
}

void CommonData::Update() {
	std::copy(std::begin(keys), std::end(keys), std::begin(preKeys));
	Novice::GetHitKeyStateAll(keys);

	camera.Update();
}

void CommonData::Draw() {
	soundManager_.PlayBGM(flugBGM_);
	soundManager_.PlaySE(flugSE_);
}
