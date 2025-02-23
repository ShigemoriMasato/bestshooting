#pragma once
#include "Common/Scene.h"
#include "../GameObject/Cursol.h"
#include <memory>

class Title : public Scene {
public:
	Title(std::shared_ptr<CommonData> commonData);
	virtual ~Title();

	void Initialize();

	std::unique_ptr<Scene> Update() override;
	void Draw() const override;

private:
	//使用するオブジェクトをここに書く
	Cursol cursol_;
};
