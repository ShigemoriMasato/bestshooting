#pragma once
#include "Common/Scene.h"
#include <memory>
#include "../GameObject/Player.h"

class PlayScene;
class PlayData;

class Game : public Scene {
public:
	Game(std::shared_ptr<CommonData> commonData);
	virtual ~Game();

	void Initialize();

	std::unique_ptr<Scene> Update() override;
	void Draw() const override;

private:
	//使用するオブジェクトをここに書く
	std::unique_ptr<PlayScene> scene_;

	std::shared_ptr<PlayData> playData_;
	std::shared_ptr<CommonData> commonData_;
	Player player_;
};

