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
	/// exeが切れるときにやるやつ。メモリ開放が自動なのでぶっちゃけ必要なし
	/// </summary>
	~SceneManager();
	CommonData* GetCommonData() { return commonData_.get(); }
private:
	std::unique_ptr<Scene> scene_;

	std::shared_ptr<CommonData> commonData_;

public:
	void Update();
	void Draw() const;
};
