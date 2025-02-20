#pragma once
#include "Vector.h"
#include <Novice.h>

class Polygon {
public:

	Polygon() = default;

	/// <summary>
	/// RGB,bright,alphaの値をcolor_に当てはめる
	/// </summary>
	/// <param name="bright">ワールド全体の明るさ</param>
	void AdjustColor(int bright = 255);

protected:

	//座標系
	Vector2 size_;			//物体の大きさ
	Vector2 pos_;			//ワールド座標系のプレイヤーの中心
	Vector2 expos_;			//微調整用のポジション()
	Vector2 scale_;			//プレイヤーの大きさの倍率
	Vector2 rotatePos_;		//kSTR行列の中心
	Vector2 velocity_;		//速度
	Vector2 direction_;		//向いている方向
	float speed_;			//速さ
	float theta_;			//回転角度(radian)
	Matrix3x3 matrix_;		//あらゆるパラメータをもとに作成する行列

	//色関係
	int red_;				//赤(0 ~ 255)
	int green_;				//緑(0 ~ 255)
	int blue_;				//青(0 ~ 255)
	int alpha_;				//透明度(0 ~ 255)
	int bright_;			//明るさ(0 ~ 255)
	unsigned int color_;	//計算後の色

	//フラグ系
	bool isActive_;			//trueのときだけ描画
	bool isBlackout_;		//AdjustColorの計算にワールド全体の明るさを反映するかどうか
};

