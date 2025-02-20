#include "PlayScene.h"

PlayScene::PlayScene(std::shared_ptr<CommonData> commonData, std::shared_ptr<PlayData> playData) {
	commonData_ = commonData;
	playData_ = playData;
}
