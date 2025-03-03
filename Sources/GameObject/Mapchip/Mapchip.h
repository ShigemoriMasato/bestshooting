#pragma once
#include "../Common/Object.h"
#include <vector>

using namespace std;

class Mapchip {
public:

	Mapchip();
	~Mapchip() = default;

	virtual enum ChipKind;

	void SetMapChip(vector<vector<ChipKind>> mapchip);

	ChipKind GetChipKind(IVector2 pos) const;

protected:

private:

	vector<vector<ChipKind>> mapchip_;
	Vector2 chipSize_;

};
