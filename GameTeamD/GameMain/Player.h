#pragma once
class C_PLAYER
{
public:

	int gOldKey;           // 前回の入力キー
	int gNowKey;           // 今回の入力キー
	int gKeyFlg;           // 入力キー情報


	int gPlayer_x = 640;


	void input();
};