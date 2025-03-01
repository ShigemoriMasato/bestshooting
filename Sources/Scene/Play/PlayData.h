#pragma once

class PlayData {
public:

	PlayData() = default;

	/// <param name="safetySec">ビートカウント開始までの時間</param>
	PlayData(int bpm, float safetySec);

	void Update();

	//以下PlayScene共通データ
	bool isTitle = false;

	float bps_{};			//BeatPerSeconds
	float seconds_{};		//何秒経過したか
	float safetySec_{};		//ビートカウント開始までの時間

	int beat_{};			//何ビート経過したか
	int flame_{};			//何フレーム経過したか
};

