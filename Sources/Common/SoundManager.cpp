#include "SoundManager.h"
#include <Novice.h>

SoundManager::SoundManager() {
	preFlugBGM_.resize(static_cast<int>(BGM::AllCount));
	handleBGM_ = 0;

	SE_.push_back(Novice::LoadAudio("./Resources/SE/privatetime.mp3"));
	volumeSE_.push_back(0.5f);
}

void SoundManager::PlayBGM(std::vector<bool>& flug) {
	for (int i = 0; i < flug.size(); i++) {
		if (flug[i] && !preFlugBGM_[i]) {
			preFlugBGM_[i] = true;
			
			for (int j = 0; j < flug.size(); j++) {
				if (j != i) {
					flug[j] = false;
					preFlugBGM_[j] = false;
				}
			}

			Novice::StopAudio(handleBGM_);

			handleBGM_ = Novice::PlayAudio(BGM_[i], true, volumeBGM_[i]);
		}

		if (!flug[i] && preFlugBGM_[i]) {
			preFlugBGM_[i] = false;
			Novice::StopAudio(handleBGM_);
		}
	}
}

void SoundManager::PlaySE(std::vector<bool>& flug) {
	for (int i = 0; i < flug.size(); i++) {
		if (flug[i]) {
			if (SE_[i] != 0) {
				Novice::PlayAudio(SE_[i], false, volumeSE_[i]);
			}
			flug[i] = false;
		}
	}
}
