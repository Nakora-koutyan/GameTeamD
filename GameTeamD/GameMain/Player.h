#pragma once
class C_PLAYER
{
public:

	int gOldKey;           // 前回の入力キー
	int gNowKey;           // 今回の入力キー
	int gKeyFlg;           // 入力キー情報


	struct PLAYER {
		int flg;          // 使用フラグ
		int x, y;         // 座標
		int w, h;         // 幅・高さ
		int count;        // タイミング用
		int speed;        // 移動
	};

	// 自機の変数宣言
	struct PLAYER gPlayer;

    gPlayer.x = 640;


	void input();
};