#pragma once
#include <memory>

class PlayData;
class CommonData;

class PlayScene {
public:

	PlayScene(std::shared_ptr<CommonData> commonData, std::shared_ptr<PlayData> playData);
	virtual ~PlayScene() = default;

	virtual std::unique_ptr<PlayScene> Update() = 0;
	virtual void Draw() const = 0;

protected:
	std::shared_ptr<PlayData> playData_;
	std::shared_ptr<CommonData> cd_;
};
