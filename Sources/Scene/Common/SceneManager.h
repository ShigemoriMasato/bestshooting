#pragma once
#include <memory>

class Scene;
class CommonData;

class SceneManager {
public:

	/// <summary>
	/// exe立ち上げのときにやるやつ
	/// </summary>
	SceneManager();

	//コピー禁止用
	SceneManager(const SceneManager&) = delete;
	SceneManager operator=(const SceneManager&) = delete;

	/// <summary>
	/// exeが切れるときにやるやつ。
	/// </summary>
	~SceneManager();
	CommonData* GetCommonData() { return commonData_.get(); }

private:

	//なんかしらのシーンのポインタを入れる変数
	std::unique_ptr<Scene> scene_;

	//共通データのポインタ
	std::shared_ptr<CommonData> commonData_;

public:
	void Update();
	void Draw() const;
};
