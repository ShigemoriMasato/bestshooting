#pragma once

class CommonData {
public:
	CommonData() = default;

	/// <summary>
	/// �L�[���͂Ȃǂ̏���
	/// </summary>
	void Update();

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};

