#include "CommonData.h"
#include <Novice.h>
#include <memory>

void CommonData::Update() {
	std::copy(std::begin(keys), std::end(keys), std::begin(preKeys));
	Novice::GetHitKeyStateAll(keys);

	camera.Update();
}
