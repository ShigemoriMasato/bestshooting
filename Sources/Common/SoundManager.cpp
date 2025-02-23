#include "SoundManager.h"

SoundManager::SoundManager() {
	preFlugBGM_.resize(static_cast<int>(BGM::AllCount));
	BGMhandle_ = -1;
}

SoundManager::~SoundManager() {
	
}
