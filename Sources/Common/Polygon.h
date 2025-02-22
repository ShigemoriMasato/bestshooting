#pragma once
#include "Vector.h"
#include <Novice.h>

class Camera;

class Polygon {
public:

	Polygon() = default;

	/// <summary>
	/// RGB,bright,alphaの値をcolor_に当てはめる
	/// </summary>
	/// <param name="bright">ワールド全体の明るさ</param>
	unsigned int AdjustColor(int bright = 255);

	/// <summary>
	/// CameraをかけたSRT行列を作成する
	/// </summary>
	/// <param name="camera"></param>
	void MakeAffineMatrix(const Camera& camera);

	/// <summary>
	/// 行列をspos_に適用する
	/// </summary>
	/// <param name="pos">spos_</param>
	Vector2 ApplyPosition(const Vector2& pos);

protected:

	//座標系
	Vector2 size_{};			//物体の大きさ
	Vector2 pos_{};				//ワールド座標系のプレイヤーの中心
	Vector2 scale_{};			//プレイヤーの大きさの倍率
	float theta_{};				//回転角度(radian)

	//色関係
	int bright_{};				//明るさ(0 ~ 255)
	unsigned int color_{};		//計算後の色

	//フラグ系
	bool isActive_{};			//trueのときだけ描画
	bool isBlackout_{};			//AdjustColorの計算にワールド全体の明るさを反映するかどうか
	bool isApplyCamera_{};		//Cameraを適用するかどうか

private:
	Matrix3x3 matrix_{};		//あらゆるパラメータをもとに作成する行列
};
