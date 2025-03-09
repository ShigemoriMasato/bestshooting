#include "Mapchip.h"

using namespace EMapchip;

Mapchip::Mapchip() {
	//chips_に各マップチップの情報を入れる
	textureHandle_ = 0;
}

void Mapchip::SetMapChip(vector<vector<int>> mapchip) {
	mapchip_ = mapchip;
}

int Mapchip::GetChipKind(IVector2 pos) const {
	return mapchip_[pos.y][pos.x];
}
