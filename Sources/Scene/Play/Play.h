#pragma once
#include "PlayScene.h"
#include"../../GameObject/Player.h"

class Play : public PlayScene {
public:
	Play(std::shared_ptr<CommonData> commonData, std::shared_ptr<PlayData> playData_);
	virtual ~Play();

	void Initialize();

	std::unique_ptr<PlayScene> Update() override;
	void Draw() const override;

private:

	//使用するオブジェクトをここに書く
	Player player_;
	Vector2 cpos_;		//Cameraのポジション
	Vector2 cscale_;	//Cameraの拡大率
	float ctheta_;		//Cameraの回転角度

};
