#pragma once
#include "PlayScene.h"
#include "../../GameObject/Object/NormalObject.h"

class PrivateTime : public PlayScene {
public:
	PrivateTime(std::shared_ptr<CommonData> commonData, std::shared_ptr<PlayData> playData_);
	virtual ~PrivateTime();

	void Initialize();

	std::unique_ptr<PlayScene> Update() override;
	void Draw() const override;

private:

	//===================Object===================
	std::vector<std::unique_ptr<NormalObject>> objects_;

	//===================Camera===================
	Vector2 cpos_;		//Cameraのポジション
	Vector2 cscale_;	//Cameraの拡大率
	float ctheta_;		//Cameraの回転角度

	bool isFirst_;		//最初のフレームかどうか

};
