#include "PlayData.h"

PlayData::PlayData(int bpm, float safetySec) {
	bps_ = bpm / 60.0f;
	safetySec_ = safetySec;
	seconds_ = 0.0f;
	beat_ = 0;
	flame_ = 0;
}

void PlayData::Update() {
	flame_++;
	seconds_ = flame_ / 60.0f;

	if (seconds_ - safetySec_ > beat_ / bps_) {
		beat_++;
	}
}
