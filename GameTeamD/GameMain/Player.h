#include"DxLib.h"
//初期値設定
class PLAYER
{
public:
	PLAYER();
	/****************************
	Playerのプロトタイプ宣言
	*****************************/
	int gPlayerImg;	//画像読込処理
	void IMAGES_PLAYER();	//プレイヤー移動処理
	void Move();
};