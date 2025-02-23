#pragma once
#include "../Common/Camera.h"
#include "../Common/SoundManager.h"

class CommonData {
public:
	CommonData();

	/// <summary>
	/// キー入力などの処理
	/// </summary>
	void Update();

	/// <summary>
	/// 音の再生等
	/// </summary>
	void Draw();

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	std::vector<bool> flugBGM_;
	std::vector<bool> flugSE_;

	Camera camera{};

	SoundManager soundManager_;
};

