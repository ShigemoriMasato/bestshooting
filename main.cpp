#include <Novice.h>
#include "Sources/Common/Camera.h"
#include "Sources/Scene/Common/SceneManager.h"

const char kWindowTitle[] = "学籍番号";

//Novice標準搭載なのでファイルに格納せず、表層にとりおいてます

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, WinSizeWidth, WinSizeHeight);

	std::unique_ptr<SceneManager> sceneManager = std::make_unique<SceneManager>();

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		sceneManager->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		sceneManager->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
