#pragma once
#include "../CommonData.h"
#include <memory>

class Scene {
public:
	//コピー禁止
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	Scene(std::shared_ptr<CommonData> commonData);
	virtual ~Scene() = default;
	virtual std::unique_ptr<Scene> Update() = 0;
	virtual void Draw() const = 0;

protected:
	std::shared_ptr<CommonData> commonData_;
	
};
