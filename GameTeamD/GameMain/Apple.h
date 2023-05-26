#pragma once
#include<stdio.h>
#include"../System/Input.h"
#include"../System/Collision.h"
#include"DxLib.h"
#define APPLE_MAX 10

struct RINGO {
	int flg;        // 使用フラグ
	int type;       // タイプ
	int img;         // 画像
	int x, y, w, h;  // 座標、幅、高さ
	int speed;       // 移動速度
	int point;       // スコア加算ポイント

};


class APPLE : public BoxCollider
{

public:
	int flg;        // 使用フラグ
	int type;       // タイプ
	int img;         // 画像
	//int x, y, w, h;  // 座標、幅、高さ
	float speed;       // 移動速度
	int count;       // 当たった数カウント
	float magnification; // 当たり判定の倍率

	APPLE();

	int gAppleImg[4];

	void AppleControl(); // リンゴの移動処理
	//int IMAGES_RINGO();              // リンゴの画像表示処理
	//void AppleSetting();

	~APPLE();
	void Draw()const;
};

