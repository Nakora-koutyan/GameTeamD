#include"Player.h"
#include"../System/Input.h"
#include"../System/PadInput.h"
#include <math.h>

PLAYER::PLAYER()
{
	//画像の読込
	try 
	{
		ImageStand = LoadGraph("Material/Images/characterStand.png");		//Image画像(直立)の読込
		if (ImageStand == -1)												//-1が検出されたらcatchへエラーを飛ばす
		{
			throw "Material/Images/characterStand.png";
		}

		LoadDivGraph("Material/Images/Dash.png", 6, 6, 1, 160, 160, ImagesDash);	//Image画像6枚(ダッシュ)の読込
		for (int i = 0; i < 6; i++)													//-1が検出されたらcatchへエラーを飛ばす
		{
			if (ImagesDash[i] == -1)
			{
				throw"Material/Images/Dash.png";							
			}
		}
		LoadDivGraph("Material/Images/walk.png", 8, 8, 1, 160, 160, ImagesWalk);	//Image画像8枚(歩行)の読込
		for (int i = 0; i < 8; i++)													//-1が検出されたらcatchへエラーを飛ばす
		{	
			if (ImagesWalk[i] == -1)
			{
				throw"Material/Images/walk.png";
			}
		}
	}
	catch (int& err) {
		printf("エラーコード%d\n", err);		//エラーの表示
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

PLAYER::~PLAYER()		//デストラクタ
{
	//フォントの削除
	DeleteFontToHandle(GuideFont);
}

void PLAYER::PLAYER_DASH()
{
	MoveLeftDash();
	MoveRightDash();
	NotTip();					//スティックが離れてる時の動作	
}

void PLAYER::MoveLeftDash()
{
	if (InputControl::TipLeftLStick(STICKL_X) < -0.7)
	{
		PlayerState = PLAYER_STATE::DASH;
		AnimInterval = ANIMATION_INTERVAL;
		TurnFlag = true;

		if (Speed > (-1 * MAX_DASH_SPEED)) {
			Speed += ((-1 * PLAYER_DASH_SPEED) / 10);
		}
	}
}

void PLAYER::MoveRightDash()
{
	if (InputControl::TipLeftLStick(STICKL_X) > 0.7)
	{
		PlayerState = PLAYER_STATE::DASH;
		AnimInterval = ANIMATION_INTERVAL;
		TurnFlag = false;

		if (Speed < MAX_DASH_SPEED) {
			Speed += (PLAYER_DASH_SPEED / 10);
		}
	}
}

void PLAYER::NotTip()
{
	if (InputControl::TipLeftLStick(STICKL_X) > -0.3 && InputControl::TipLeftLStick(STICKL_X) < 0.3)
		{
			Speed -= (Speed * 0.3);

			if (InputControl::TipLeftLStick(STICKL_X) < 0 || InputControl::TipLeftLStick(STICKL_X) == 0)
			{
				if (fabsf(Speed) > 1 && fabsf(Speed) < 5)	//Speedの値が１以上5未満の時
				{
					PlayerState = PLAYER_STATE::DASH;		//プレイヤーの状態をダッシュにする
					AnimInterval = ANIMATION_INTERVAL + 1;	//
				}
			}
		else if (fabsf(Speed) < 1)					//Speedの値が１以下の時
		{
			AnimTimer = 0;
			AnimType = 0;
			PlayerState = PLAYER_STATE::IDOL;
			Image = ImageStand;
		}
	}
}

void PLAYER::Update() //キャラクターの移動と状態の更新
{
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

	}
}

void PLAYER::DashAnimation()
{
	if (AnimTimer++ % AnimInterval == 0)
	{
		Image = ImagesDash[AnimType++ % 6];
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