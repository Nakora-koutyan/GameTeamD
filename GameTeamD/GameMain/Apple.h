#pragma once
#include<stdio.h>
#include"../System/Input.h"
#include"DxLib.h"

class APPLE
{
public:

	void AppleControl(); // リンゴの移動処理
	int CreateApple();   // リンゴの生成処理
	int AppleProd();     // リンゴの生成率
};