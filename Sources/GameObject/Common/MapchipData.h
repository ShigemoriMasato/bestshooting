#pragma once
#include "../Common/Object.h"
#include "Chip.h"
#include <vector>

using namespace std;

/// <summary>
/// CommonMapchip
/// </summary>
class MapchipData {
public:

	MapchipData();
	~MapchipData() = default;

	virtual void Draw() = 0;

	void SetMapChip(vector<vector<int>> mapchip);

	int GetChipKind(IVector2 pos) const;

protected:

	vector<vector<int>> mapchip_;
	Vector2 chipSize_;
	int textureHandle_;

};
