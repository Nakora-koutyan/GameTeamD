#pragma once
#include"DxLib.h"
#include"../System/Collision.h"
#include"../System/PadInput.h"

#include<math.h>

//初期値設定
#define PLAYER_WALK_SPEED	4		//歩行スピードの初期値
#define PLAYER_DASH_SPEED	10.0f	//ダッシュスピードの初期値
#define MAX_DASH_SPEED		5		//

//プレイヤーの初期状態
#define PLAYER_STATE_IDOL	0		//プレイヤーの直立状態
#define PLAYER_STATE_WALK	1		//プレイヤーの歩行状態
#define PLAYER_STATE_DASH	2		//プレイヤーのダッシュ状態

#define ANIMATION_INTERVAL	3		//アニメーション切り替えの間隔

class PLAYER:public BoxCollider
{
public:
	int TurnFlag;
	enum PLAYER_STATE
	{
		IDOL = 0,
		WALK,
		DASH
	};

	//プレイヤーの状態宣言
	PLAYER_STATE PlayerState;				//プレイヤーの現在の状態を制御

	//プレイヤー画像用の配列・変数宣言
	int ImageStand;					//画像用変数(直立)
	int ImagesDash[6];				//画像用配列(歩行)
	int ImagesWalk[8];				//画像用配列(ダッシュ)
	int Image;						//画像

	//画像切り替えに関する変数宣言
	int AnimTimer;					//アニメーション画像切り替え用タイマー
	int AnimInterval;				//アニメーション切り替え間隔
	int AnimType;					//アニメーションタイプ

	float Speed;					//プレイヤーのスピード値

	int WalkSE;						//歩行SE
	int DashSE;						//ダッシュSE
	int GuideFont;

private:

	void DashAnimation();			//走行アニメーション
	void WalkAnimation();			//歩行アニメーション


private:
	//スティックの動作に伴うキャラクターの移動方向とダッシュ
	void MoveLeftDash()
	{
		if (InputControl::TipLeftLStick(STICKL_X) < -0.7)
		{
			PlayerState = PLAYER_STATE::DASH;
			AnimInterval = ANIMATION_INTERVAL;
			TurnFlag = true;
			
			if (Speed > ( - 1 * MAX_DASH_SPEED)) {
				Speed += ((- 1 * PLAYER_DASH_SPEED) / 10);
			}
		}
		else if (InputControl::TipLeftLStick(STICKL_X) > -0.3 && InputControl::TipLeftLStick(STICKL_X) < 0.3)
		{
			Speed += (Speed * 0.3);
			TurnFlag = true;


			if (InputControl::TipLeftLStick(STICKL_X) > 0 || InputControl::TipLeftLStick(STICKL_X) == 0)
			{
				TurnFlag = true;
				if (fabsf(Speed) > 1 && fabsf(Speed) < 5)
				{
					PlayerState = PLAYER_STATE::DASH;
					AnimInterval = ANIMATION_INTERVAL + 1;
					TurnFlag = true;
				}
				else if (fabsf(Speed) < 1)
				{
					AnimTimer = 0;
					AnimType = 0;
					PlayerState = PLAYER_STATE::IDOL;
					Image = ImageStand;
					TurnFlag = true;
				}
			}
		}
	}

	void MoveRightDash() 
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
		else if (InputControl::TipLeftLStick(STICKL_X) > -0.3 && InputControl::TipLeftLStick(STICKL_X) < 0.3)
		{
			Speed -= (Speed * 0.3);
			TurnFlag = false;

			if (InputControl::TipLeftLStick(STICKL_X) < 0 || InputControl::TipLeftLStick(STICKL_X) == 0) 
			{
				TurnFlag = false;
				if (fabsf(Speed) > 1 && fabsf(Speed) < 5)	//Speedの値が１以上5未満の時
				{
					PlayerState = PLAYER_STATE::DASH;		//プレイヤーの状態をダッシュにする
					AnimInterval = ANIMATION_INTERVAL + 1;	//
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
	}


public:
	//コンストラクタ
	PLAYER();

	//デストラクタ
	~PLAYER();

	//プレイヤーの現在の状態の更新
	void Update();

	//描画
	void Draw() const;

	//状態のリセット
	void Reset();
;
};