#pragma once
#include "../Common/Texture.h"
#include "../Common/Object.h"

class MapchipData;

class MapChipController {
public:

	MapChipController();
	~MapChipController() = default;

	void SetData(MapchipData data);

	void Draw();

private:



};
