#include "Mapchip.h"

ChipKind Mapchip::GetChipKind(IVector2 pos) const {
	return mapchip_[pos.y][pos.x];
}
