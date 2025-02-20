#pragma once
#include "Common/Scene.h"
#include <memory>

class PlayScene;
class PlayData;

class Play : public Scene {
public:
	Play(std::shared_ptr<CommonData> commonData);
	virtual ~Play();

	void Initialize();

	std::unique_ptr<Scene> Update() override;
	void Draw() const override;

private:
	//使用するオブジェクトをここに書く
	std::unique_ptr<PlayScene> scene_;

	std::shared_ptr<PlayData> playData_;
	std::shared_ptr<CommonData> commonData_;
};

