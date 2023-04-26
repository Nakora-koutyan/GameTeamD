#pragma once
#include "DxLib.h"

#define BUTTONS 16

//スティック
struct Stick
{
	short ThumbX;	//横軸値
};

class C_PLAYER
{
private:
	int gOldKey[BUTTONS];           // 前回の入力キー
	int gNowKey;           // 今回の入力キー
	int gKeyFlg;           // 入力キー情報


	int gPlayer_x;

	int gPlayerimages;
public:
	C_PLAYER()
	{
		gOldKey = 0;
		gNowKey = 0;
		gKeyFlg = 0;

		gPlayer_x = 640;
		gPlayerimages = LoadGraph("Material/Images/characterWalk02.png");
	}
	~C_PLAYER()
	{

	}
	void Update();
	void Draw() const;
};