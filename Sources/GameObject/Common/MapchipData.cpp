#include "MapchipData.h"

using namespace EMapchip;

MapchipData::MapchipData() {
	//chips_に各マップチップの情報を入れる
	textureHandle_ = 0;
}

void MapchipData::SetMapChip(vector<vector<int>> mapchip) {
	mapchip_ = mapchip;
}

int MapchipData::GetChipKind(IVector2 pos) const {
	return mapchip_[pos.y][pos.x];
}
