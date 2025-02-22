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

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

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
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
