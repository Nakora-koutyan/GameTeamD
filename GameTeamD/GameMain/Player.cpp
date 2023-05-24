#include"Player.h"
#include"../System/Input.h"
#include"../System/PadInput.h"
#include <math.h>

PLAYER::PLAYER()
{
	//画像の読込
	try 
	{
		ImageStand = LoadGraph("Material/Images/characterStand.png");				//直立
		if (ImageStand == -1)
		{
			throw "Material/Images/characterStand.png";
		}

		LoadDivGraph("Material/Images/Dash.png", 6, 6, 1, 160, 160, ImagesDash);	//ダッシュ
		for (int i = 0; i < 6; i++)
		{
			if (ImagesDash[i] == -1)
			{
				throw"Material/Images/Dash.png";							
			}
		}
		LoadDivGraph("Material/Images/walk.png", 8, 8, 1, 160, 160, ImagesWalk);	//歩行
		for (int i = 0; i < 8; i++)
		{	
			if (ImagesWalk[i] == -1)
			{
				throw"Material/Images/walk.png";
			}
		}
	}
	catch (int& err) {
		printf("エラーコード%d\n", err);
	}

	TurnFlag = false;

	//プレイヤー当たり判定の値の初期化
	location.x = 100;
	location.y = 500;
	erea.width = 50;
	erea.height = 100;
	erea.width_rate = 0.6;
	erea.height_rate = 0.5;

	//プレイヤーの状態の初期化
	PlayerState = PLAYER_STATE::IDOL;
	Speed = 0;
	AnimTimer = 0;
	AnimInterval = 0;
	AnimType = 0;

	//画像の初期化
	Image = ImageStand;
	ImagesDash;
	//location.x = 100;
}

PLAYER::~PLAYER()
{
	//フォントの削除
	DeleteFontToHandle(GuideFont);
}

void PLAYER::Update() //キャラクターの移動と状態の更新
{
	//スティックの傾き割合 > 5割
	if (InputControl::TipLeftLStick(STICKL_X) < -0.7 || InputControl::TipLeftLStick(STICKL_X) > 0.7)
	{
		if (PlayerState != PLAYER_STATE::DASH)
		{
			PlayerState = PLAYER_STATE::DASH;
			AnimInterval = ANIMATION_INTERVAL;
			AnimTimer = 0;
			AnimType = 0;
		}
		
		if (InputControl::TipLeftLStick(STICKL_X) < -0.7)
		{
			Speed = -PLAYER_DASH_SPEED;
			TurnFlag = true;
		}
		if (InputControl::TipLeftLStick(STICKL_X) > 0.7)
		{
			Speed = PLAYER_DASH_SPEED;
			TurnFlag = false;
		}
	}
	else if (InputControl::TipLeftLStick(STICKL_X) < -0.3 || InputControl::TipLeftLStick(STICKL_X) > 0.3)
	{
		if (PlayerState != PLAYER_STATE::WALK)
		{
			PlayerState = PLAYER_STATE::WALK;
			AnimInterval = ANIMATION_INTERVAL;
			AnimTimer = 0;
			AnimType = 0;
		}

		if (InputControl::TipLeftLStick(STICKL_X) < -0.3)
		{
			Speed = -PLAYER_WALK_SPEED;
			TurnFlag = true;
		}

		if (InputControl::TipLeftLStick(STICKL_X) > 0.3)
		{
			Speed = PLAYER_WALK_SPEED;
			TurnFlag = false;
		}
	}
	else if (PlayerState != PLAYER_STATE::IDOL)
	{
		AnimTimer = 0;
		AnimType = 0;
		PlayerState = PLAYER_STATE::IDOL;
		Image = ImageStand;
		Speed = 0;
	}

	else{}

	switch(PlayerState)
	{
	case PLAYER_STATE::IDOL:
		if (CheckSoundMem(WalkSE) == 1)
		{
			StopSoundMem(WalkSE);
		}
		if (CheckSoundMem(DashSE) == -1)
		{
			StopSoundMem(DashSE);
		}
		break;
	case PLAYER_STATE::WALK:
		if (CheckSoundMem(DashSE) == 1)
		{
			PlaySoundMem(WalkSE,DX_PLAYTYPE_BACK,TRUE);
		}
		if (CheckSoundMem(DashSE) == 1)
		{
			StopSoundMem(DashSE);
		}
		WalkAnimation();
		location.x += Speed;
		break;
	case PLAYER_STATE::DASH:
		if (CheckSoundMem(DashSE) == 1)
		{
			PlaySoundMem(WalkSE, DX_PLAYTYPE_BACK, TRUE);
		}
		if (CheckSoundMem(DashSE) == 1)
		{
			StopSoundMem(DashSE);
		}
		DashAnimation();
		location.x += Speed;
		break;

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

void PLAYER::Draw()const
{
	DrawRotaGraph(location.x, location.y, 1.0, 0, Image, TRUE, TurnFlag);	//画面にプレイヤーの表示
}

void PLAYER::Reset()
{
	TurnFlag = false;
	location.x = 100;
	location.y = 500;
	Speed = 0;
	AnimTimer = 0;
	AnimInterval = 0;
	AnimType = 0;
	PlayerState = PLAYER_STATE::IDOL;
	Image = ImageStand;
}