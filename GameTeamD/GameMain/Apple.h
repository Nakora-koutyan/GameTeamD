#pragma once
#include<stdio.h>
#include"../System/Input.h"
#include"DxLib.h"

class APPLE
{
public:

	APPLE();

	void AppleControl(); // ƒŠƒ“ƒS‚ÌˆÚ“®ˆ—
	int CreateApple();   // ƒŠƒ“ƒS‚Ì¶¬ˆ—
	int AppleProd();     // ƒŠƒ“ƒS‚Ì¶¬—¦
	int gAppleImg[4];
	//int IMAGES_RINGO();              // ƒŠƒ“ƒS‚Ì‰æ‘œ•\¦ˆ—
	//void AppleSetting();

	~APPLE();
};

