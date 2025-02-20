#pragma once

class CommonData {
public:
	CommonData() = default;

	/// <summary>
	/// ƒL[“ü—Í‚È‚Ç‚Ìˆ—
	/// </summary>
	void Update();

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};

