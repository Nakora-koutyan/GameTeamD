#include<stdio.h>
#include"DxLib.h"
#include"Player.h"
#include"../System/Input.h"
#include"../System/PadInput.h"
#include"math.h"

PLAYER::PLAYER()
{
	//初期化
	AnimTimer = 0;
	AnimInterval = 0;
	AnimType = 0;
	Image = ImageStand;
	ImagesDash;
	location.x = 100;
}

PLAYER::~PLAYER()
{

}
void PLAYER::Update() //キャラクターの移動と状態の更新
{
	//スティックの傾き割合 > 5割
	if (InputControl::TipLeftLStick(STICKL_X) > 0.5)
	{
		//5割以上

	}
}

void PLAYER::DashAnimation()
{

	if (AnimTimer++ % AnimInterval == 0)
	{
		Image = ImagesDash[AnimType++ % 6];
	}
}
void PLAYER::WalkAnimation()
{
	if (AnimTimer++ % AnimInterval == 0)
	{
		Image = ImagesWalk[AnimType++ % 8];
	}
}