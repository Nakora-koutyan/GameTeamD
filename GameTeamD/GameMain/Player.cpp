#include"Player.h"
#include"../System/Input.h"
#include"../System/PadInput.h"
#include <math.h>

PLAYER::PLAYER()
{
	//画像の読込
	try
	{
		image_stand = LoadGraph("Material/Images/characterStand.png");		//Image画像(直立)の読込
		if (image_stand == -1)												//-1が検出されたらcatchへエラーを飛ばす
		{
			throw "Material/Images/characterStand.png";
		}

		LoadDivGraph("Material/Images/Dash.png", 6, 6, 1, 160, 160, images_dash);	//Image画像6枚(ダッシュ)の読込
		for (int i = 0; i < 6; i++)													//-1が検出されたらcatchへエラーを飛ばす
		{
			if (images_dash[i] == -1)
			{
				throw"Material/Images/Dash.png";
			}
		}
		LoadDivGraph("Material/Images/walk.png", 8, 8, 1, 160, 160, images_walk);	//Image画像8枚(歩行)の読込
		for (int i = 0; i < 8; i++)													//-1が検出されたらcatchへエラーを飛ばす
		{
			if (images_walk[i] == -1)
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
	location.y = 600;
	erea.width = 50;
	erea.height = 100;
	erea.width_rate = 0.6f;
	erea.height_rate = 0.5f;

	//プレイヤーの状態の初期化
	speed = 0;
	anim_timer = 0;
	anim_interval = 0;
	anim_type = 0;

	//画像の初期化
	image = image_stand;
	images_dash;
	images_walk;
	//location.x = 100;

	PlayerState ;
}

PLAYER::~PLAYER()		//デストラクタ
{
	//フォントの削除
	DeleteFontToHandle(guide_font);
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
		anim_interval = ANIMATION_INTERVAL;
		TurnFlag = true;

		if (speed > (-MAX_DASH_SPEED)) {
			speed += ((-PLAYER_DASH_SPEED) / 10);
		}
	}
}

void PLAYER::MoveRightDash()
{
	if (InputControl::TipLeftLStick(STICKL_X) > 0.7)
	{
		PlayerState = PLAYER_STATE::DASH;
		anim_interval = ANIMATION_INTERVAL;
		TurnFlag = false;

		if (speed < MAX_DASH_SPEED) {
			speed += (PLAYER_DASH_SPEED / 10);
		}
	}
}

void PLAYER::NotTip()
{
	if (InputControl::TipLeftLStick(STICKL_X) > -0.3 && InputControl::TipLeftLStick(STICKL_X) < 0.3)
	{
		speed -= (speed * 0.05f);

		if (fabsf(speed) >= 1.0f)	//Speedの値が１以上5未満の時
		{
			PlayerState = PLAYER_STATE::DASH;		//プレイヤーの状態をダッシュにする
			anim_interval = ANIMATION_INTERVAL + 3;	//
		}
		else if (fabsf(speed) < 0)					//Speedの値が１以下の時
		{
			anim_timer = 0;
			anim_type = 0;
			PlayerState = PLAYER_STATE::IDOL;
			image = image_stand;
			speed = 0;
		}
	}
}

void PLAYER::Update() //キャラクターの移動と状態の更新
{
	PLAYER_DASH();

	switch(PlayerState)
	{
	case PLAYER_STATE::IDOL:
		if (CheckSoundMem(walk_se) == 1)
		{
			StopSoundMem(walk_se);
		}
		if (CheckSoundMem(dash_se) == -1)
		{
			StopSoundMem(dash_se);
		}
		break;
	case PLAYER_STATE::DASH:
		if (CheckSoundMem(dash_se) == 1)
		{
			PlaySoundMem(walk_se, DX_PLAYTYPE_BACK, TRUE);
		}
		if (CheckSoundMem(dash_se) == 1)
		{
			StopSoundMem(dash_se);
		}
		DashAnimation();
		location.x += speed;

	}
}

void PLAYER::DashAnimation()
{
	if (anim_timer++ % anim_interval == 0)
	{
		image = images_dash[anim_type++ % 6];
	}
}

void PLAYER::Draw()const
{
	DrawRotaGraph((int)location.x, (int)location.y, 1.0, 0, image, TRUE, TurnFlag);	//画面にプレイヤーの表示
}

void PLAYER::Reset()
{
	TurnFlag = false;
	location.x = 100;
	location.y = 500;
	speed = 0;
	anim_timer = 0;
	anim_interval = 0;
	anim_type = 0;
	PlayerState = PLAYER_STATE::IDOL;
	image = image_stand;
}