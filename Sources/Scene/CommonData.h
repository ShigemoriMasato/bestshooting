#pragma once

class CommonData {
public:
	CommonData() = default;

	/// <summary>
	/// キー入力などの処理
	/// </summary>
	void Update();

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};

