#include"DxLib.h"
//初期値設定
class PLAYER
{
public:
	PLAYER();

	/****************************
	Playerのプロトタイプ宣言
	*****************************/
	int gPlayerImg;			//プレイヤー画像
	void IMAGES_PLAYER();	//プレイヤーの画像表示処理
	void Move();
};