#pragma once
#include<stdio.h>
#include"../System/Input.h"
#include"DxLib.h"

class APPLE
{
public:

	APPLE();

	int gAppleImg[4];

	void AppleControl(); // リンゴの移動処理
	int CreateApple();   // リンゴの生成処理
	int AppleProd();     // リンゴの生成率
	int IMAGES_RINGO();              // リンゴの画像表示処理
	void AppleSetting();

	~APPLE();
};

