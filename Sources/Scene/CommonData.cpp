#include "CommonData.h"
#include <Novice.h>

void CommonData::Update() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}
