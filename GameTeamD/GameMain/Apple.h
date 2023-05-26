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
	int point;       // スコア加算ポイント
	int gAppleImg[4];

	float speed;       // 移動速度
	float magnification; // 当たり判定の倍率

	APPLE();
	~APPLE();

	void AppleControl(); // リンゴの移動処理
	void Draw()const;
};

