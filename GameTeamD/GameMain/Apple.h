#pragma once
#include<stdio.h>
#include"../System/Input.h"
#include"DxLib.h"

class APPLE
{
private:

	int gItemImg[4];       // アイテム画像

public:

	int IMAGES_RINGO();              // リンゴの画像表示処理
	void AppleControl(void); // リンゴの移動処理
	int CreateApple(void);   // リンゴの生成処理

};

