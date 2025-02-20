#pragma once
#include "PlayScene.h"

class Game : public PlayScene {
public:
	Game(std::shared_ptr<CommonData> commonData, std::shared_ptr<PlayData> playData_);
	virtual ~Game();

	void Initialize();

	std::unique_ptr<PlayScene> Update() override;
	void Draw() const override;

private:



};
