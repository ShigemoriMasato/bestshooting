#include "PlayScene.h"

PlayScene::PlayScene(std::shared_ptr<CommonData> commonData, std::shared_ptr<PlayData> playData) {
	cd_ = commonData;
	playData_ = playData;
}
