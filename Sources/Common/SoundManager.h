#pragma once
#include <vector>

enum class BGM {
	PrivateTime,

	AllCount
};

enum class SE {

	AllCount
};

class SoundManager {
public:

	SoundManager();
	~SoundManager() = default;

	/// <summary>
	/// BGMを再生する(多重再生対策済み)
	/// </summary>
	/// <param name="flug">commonData.flugBGM</param>
	void PlayBGM(std::vector<bool>& flug);

	/// <summary>
	/// SEを再生する
	/// </summary>
	/// <param name="flug">commonData.flugSE</param>
	void PlaySE(std::vector<bool>& flug);

	int GetHandleBGM() const;

private:

	std::vector<bool> preFlugBGM_;
	int handleBGM_;

	std::vector<int> BGM_;
	std::vector<int> SE_;

	std::vector<float> volumeBGM_;
	std::vector<float> volumeSE_;
};
